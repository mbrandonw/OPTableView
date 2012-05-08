OPTableView
===========

`OPTableView` is a subclass of `UITableView` adding 2 new features:

* Row snapping: optionally force the table view to snap to a specific row after dragging/scrolling has stopped.

* Horizontal scrolling: after nearly writing my own `UIScrollView` subclass to handle large scrolling lists that move horizontally, I realized that a standard `UITableView` with a `CAAffineTransform` applied could accomplish the same thing.

## Row Snapping

Setting the flag `.snapToRows = YES` on your table view will cause it to find the most 'appropriate' row to snap to once dragging and/or scrolling ends. The delegate method `tableView:shouldSnapToIndexPath:` allows you to also tweak the row to snap to just before the snapping occurs. If this method returns `nil` then the table view will go into free scrolling.

There are also delegate methods for being notified when snapping is about to occur, and when it finishes.

## Horizontal Scrolling

Setting the flag `.horizontal = YES` on your table view causes it's cells to be layed out horizintally, with scrolling going from left to right. This is achieved by applying a `CGAffineTransform` to the table view to rotate it, and then to each table view cell to undo the rotation. 

There is no support for section headers/footers right now, mostly because I can't think of a good use for them (I think it would look weird when they accumulate on the left/right). More importantly, there is not currently any support for `tableHeaderView` and `tableFooterView`, but I *do* want to support that, so I've opened an [issue](https://github.com/mbrandonw/OPTableView/issues/1).
##Installation

We love [CocoaPods](http://github.com/cocoapods/cocoapods), so we recommend you use it.

##Author

Brandon Williams  
[@mbrandonw](http://www.twitter.com/mbrandonw)  
[www.opetopic.com](http://www.opetopic.com)

## License

OPTableView is available under the MIT license. See the LICENSE file for more info.