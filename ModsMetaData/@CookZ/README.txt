A couple of parameters can be configured via a server config file. This file is generated with
default values at "$missionFolder\CookZ\CookZ.json" the first time you start the server with the
mod installed. After you modify the configuration, you need to restart the server.

(!) If the mod is updated and new configuration is added, then a file with an inceremented version suffix is created,
    e.g. CookZ_V023.json you need to delete the current. You need to add your changes from the last version and
    restart your server - but you only need to keep the latest version.

The file has the following default content. Here, enriched by some documentation.

Boolean values are set by 1 to true and by 0 to false.

{
    // can the user craft the cookbook - for servers that want to add the book to the spawn pool or trader, set to 0
    "CanCraftCookBook": 1,

    // can the user craft empty cans - for servers that want to add empty cans to the spawn pool or trader, set to 0
    "CanCraftEmptyCans": 1,

    // can the user craft empty boxes - for servers that want to add empty boxes to the spawn pool or trader, set to 0
    "CanCraftEmptyBoxes": 1,

    // some ingredients have a quantity - this sets the minimum quantity to be used as an ingredient to 50%
    // must be 0 < MinIngredientQuantityPercent <= 100
    "MinIngredientQuantityPercent": 50
}
