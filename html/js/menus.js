menus = [
	"main",
	"options"
];

function populateResolutions()
{
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