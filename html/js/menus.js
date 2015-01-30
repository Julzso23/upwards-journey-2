menus = [
	"main",
	"options"
];

function populateResolutions()
{
	$("#options-video ul.dropdown-menu").html("");
	$.each(window.getResolutions(), function(key, value)
	{
		$("#options-video ul.dropdown-menu").append(
			'<li role="presentation"><a role="menuitem" tabindex="-1" href="" onclick="window.setResolution(' + value[0] + ', ' + value[1] + ')">' + value[0] + ' x ' + value[1] + '</a></li>');
	});
}

function setMenu(menu)
{
	$("div.menu:visible").hide("drop", {direction: (Math.floor(Math.random()*2) ? "up" : "down")}, 200, function()
	{
		$("#"+menu).show("slide", {direction: (Math.floor(Math.random()*2) ? "left" : "right")}, 300);
	});
}

$(document).ready(function()
{
	setMenu("main");
});