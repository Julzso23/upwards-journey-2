#ifndef GUI_HTMLMENU_H
#define GUI_HTMLMENU_H

#include <SFML\Graphics.hpp>
#include <Awesomium\WebCore.h>
#include <Awesomium\BitmapSurface.h>
#include <Awesomium\STLHelpers.h>
#include <functional>
#include <vector>

namespace GUI
{
	struct JSMethod
	{
		Awesomium::WebString name;
		std::function<void(const Awesomium::JSArray& args)> function;
	};
	struct JSMethodWithReturn
	{
		Awesomium::WebString name;
		std::function<Awesomium::JSValue(const Awesomium::JSArray& args)> function;
	};

	class MethodCallHandler : public Awesomium::JSMethodHandler
	{
	private:
		std::vector<JSMethod> methods;
		std::vector<JSMethodWithReturn> returnMethods;
	public:
		void OnMethodCall(Awesomium::WebView* caller, unsigned int remoteObjectId, const Awesomium::WebString& methodName, const Awesomium::JSArray& args);
		Awesomium::JSValue OnMethodCallWithReturnValue(Awesomium::WebView* caller, unsigned int remoteObjectId, const Awesomium::WebString& methodName, const Awesomium::JSArray& args);
		void addJSMethod(Awesomium::WebString name, std::function<void(const Awesomium::JSArray& args)> function);
		void addJSMethodWithReturn(Awesomium::WebString name, std::function<Awesomium::JSValue(const Awesomium::JSArray& args)> function);
	};

	class HTMLMenu : public sf::Drawable
	{
	private:
		Awesomium::WebCore* webCore;
		Awesomium::WebView* view;
		MethodCallHandler* methodCallHander;
		sf::Texture* texture;
		sf::Sprite sprite;

		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	public:
		HTMLMenu(std::string fileName, sf::Vector2u size);

		void addJSMethod(Awesomium::WebString name, std::function<void(const Awesomium::JSArray& args)> function);
		void addJSMethodWithReturn(Awesomium::WebString name, std::function<Awesomium::JSValue(const Awesomium::JSArray& args)> function);

		void update();

		void mousePressed(sf::Mouse::Button button, sf::Vector2i position);
		void mouseReleased(sf::Mouse::Button button, sf::Vector2i position);
		void mouseMoved(int x, int y);

		void windowResized(sf::Vector2u size);

		void onExit();
	};
}

#endif