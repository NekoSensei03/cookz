A couple of parameters can be configured via a server config file. This file is generated with
default values at "$missionFolder\CookZ\CookZ.json" the first time you start the server with the
mod installed. After you modify the configuration, you need to restart the server.

(!) If the mod is updated and new configuration is added, then you need to delete the current
    file at "$missionFolder\CookZ\CookZ.json", start the server so it gets re-generated, do
    modifications if necessary and restart the server.

The file has the following default content. Here, enriched by some documentation.

Boolean values are set by 1 to true and by 0 to false.

{
    // can the user craft the cookbook - for servers that want to add the book to the spawn pool or trader, set to 0
    "CanCraftCookBook": 1,

    // can the user craft empty cans - for servers that want to add empty cans to the spawn pool or trader, set to 0
    "CanCraftEmptyCans": 1,

    // can the user craft empty boxes - for servers that want to add empty boxes to the spawn pool or trader, set to 0
    "CanCraftEmptyBoxes": 1
}
