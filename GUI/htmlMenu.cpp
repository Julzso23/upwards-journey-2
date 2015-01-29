#include "HTMLMenu.h"

namespace GUI
{
	using namespace Awesomium;
	void MethodCallHandler::OnMethodCall(WebView* caller, unsigned int remoteObjectId, const WebString& methodName, const JSArray& args)
	{
		for (int i = 0; i < methods.size(); i++)
			if (methods[i].name == methodName)
				methods[i].function(args);
	}
	JSValue MethodCallHandler::OnMethodCallWithReturnValue(WebView* caller, unsigned int remoteObjectId, const WebString& methodName, const JSArray& args)
	{
		for (int i = 0; i < returnMethods.size(); i++)
			if (returnMethods[i].name == methodName)
				return returnMethods[i].function(args);
		return JSValue();
	}

	void MethodCallHandler::addJSMethod(WebString name, std::function<void(const JSArray& args)> function)
	{
		JSMethod method;
		method.name = name;
		method.function = function;
		methods.insert(methods.end(), method);
	}
	void MethodCallHandler::addJSMethodWithReturn(WebString name, std::function<JSValue(const JSArray& args)> function)
	{
		JSMethodWithReturn method;
		method.name = name;
		method.function = function;
		returnMethods.insert(returnMethods.end(), method);
	}

	HTMLMenu::HTMLMenu(std::string fileName, sf::Vector2u size)
	{
		webCore = WebCore::Initialize(WebConfig());

		view = webCore->CreateWebView(size.x, size.y);
		view->LoadURL(WebURL(WSLit(std::string("file:///html/" + fileName + ".html").data())));
		view->SetTransparent(true);
		methodCallHander = new MethodCallHandler();
		view->set_js_method_handler(methodCallHander);

		texture = new sf::Texture();
		texture->create(size.x, size.y);
		sprite.setTexture(*texture);

		while (view->IsLoading())
			webCore->Update();
		Sleep(300);
		webCore->Update();
	}

	void HTMLMenu::addJSMethod(WebString name, std::function<void(const JSArray& args)> function)
	{
		JSValue window = view->ExecuteJavascriptWithResult(WSLit("window"), WSLit(""));
		if (window.IsObject())
		{
			window.ToObject().SetCustomMethod(name, false);
		}
		methodCallHander->addJSMethod(name, function);
	}
	void HTMLMenu::addJSMethodWithReturn(WebString name, std::function<JSValue(const JSArray& args)> function)
	{
		JSValue window = view->ExecuteJavascriptWithResult(WSLit("window"), WSLit(""));
		if (window.IsObject())
		{
			window.ToObject().SetCustomMethod(name, true);
		}
		methodCallHander->addJSMethodWithReturn(name, function);
	}

	void HTMLMenu::update()
	{
		webCore->Update();
	}

	void HTMLMenu::mousePressed(sf::Mouse::Button button, sf::Vector2i position)
	{
		switch (button)
		{
		case sf::Mouse::Left: view->InjectMouseDown(MouseButton::kMouseButton_Left);
		case sf::Mouse::Middle: view->InjectMouseDown(MouseButton::kMouseButton_Middle);
		case sf::Mouse::Right: view->InjectMouseDown(MouseButton::kMouseButton_Right);
		}
		view->InjectMouseMove(position.x, position.y);
	}
	void HTMLMenu::mouseReleased(sf::Mouse::Button button, sf::Vector2i position)
	{
		switch (button)
		{
		case sf::Mouse::Left: view->InjectMouseUp(MouseButton::kMouseButton_Left);
		case sf::Mouse::Middle: view->InjectMouseUp(MouseButton::kMouseButton_Middle);
		case sf::Mouse::Right: view->InjectMouseUp(MouseButton::kMouseButton_Right);
		}
		view->InjectMouseMove(position.x, position.y);
	}
	void HTMLMenu::mouseMoved(int x, int y)
	{
		view->InjectMouseMove(x, y);
	}

	void HTMLMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		BitmapSurface* surface = (BitmapSurface*)view->surface();
		sf::Uint8* buffer = new sf::Uint8[surface->width() * surface->height() * 4];
		surface->CopyTo(buffer, surface->row_span(), 4, true, false);
		texture->update(buffer);
		delete buffer;
		target.draw(sprite, states);
	}

	void HTMLMenu::windowResized(sf::Vector2u size)
	{
		view->Resize(size.x, size.y);
		texture->create(size.x, size.y);
	}

	void HTMLMenu::onExit()
	{
		delete texture;
		delete methodCallHander;
		view->Destroy();
		WebCore::Shutdown();
	}
}