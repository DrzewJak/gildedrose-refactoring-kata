#include "GildedRose.h"


GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}

void GildedRose::updateQuality() {
    for (int i = 0; i < items.size(); i++) {
        updateItemQuality(items[i]);
    }
}

void GildedRose::updateItemQuality(Item& item) {
    if (item.name != "Aged Brie" && item.name != "Backstage passes to a TAFKAL80ETC concert" && item.name != "Sulfuras, Hand of Ragnaros") {
        updateNormalItem(item);
    }
    else if (item.name == "Aged Brie") {
        updateAgedBrie(item);
    }
    else if (item.name == "Backstage passes to a TAFKAL80ETC concert") {
        updateBackstagePass(item);
    }
}

void GildedRose::updateNormalItem(Item& item) {
    if (item.quality > 0) {
        if (item.name != "Sulfuras, Hand of Ragnaros") {
            item.quality--;
        }
    }
    item.sellIn--;

    if (item.sellIn < 0 && item.quality > 0 && item.name != "Sulfuras, Hand of Ragnaros") {
        item.quality--;
    }
}

void GildedRose::updateAgedBrie(Item& item) {
    if (item.quality < 50) {
        item.quality++;
    }
    item.sellIn--;

    if (item.sellIn < 0 && item.quality < 50) {
        item.quality++;
    }
}

void GildedRose::updateBackstagePass(Item& item) {
    if (item.quality < 50) {
        item.quality++;

        if (item.sellIn < 11 && item.quality < 50) {
            item.quality++;
        }

        if (item.sellIn < 6 && item.quality < 50) {
            item.quality++;
        }
    }
    item.sellIn--;

    if (item.sellIn < 0) {
        item.quality = 0;
    }
}