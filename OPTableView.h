// OPTableView
//
// Copyright (c) 2012 Brandon Williams (http://www.opetopic.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <UIKit/UIKit.h>

@class OPTableView;
@protocol OPTableViewDelegate <UITableViewDelegate>
@optional

/**
 Called just before the table view snaps to a row. Called only when snapsToRows = YES.
 */
-(void) tableView:(OPTableView*)tableView willSnapToIndexPath:(NSIndexPath*)indexPath;

/**
 Called just after the table view snaps to a row. Called only when snapsToRows = YES or pagingEnabled = YES.
 */
-(void) tableView:(OPTableView*)tableView didSnapToIndexPath:(NSIndexPath*)indexPath;

/**
 This delegate methods passes you the index path it is about to snap to, and you return the index path
 it should snap to. If you don't implement this method it will snap to the default index path. If you 
 return nil then the table view will scroll freely. Only works when snapsToRows = YES.
 */
-(NSIndexPath*) tableView:(UITableView *)tableView shouldSnapToIndexPath:(NSIndexPath*)indexPath;
@end

@interface OPTableView : UITableView

@property (nonatomic, assign) id<OPTableViewDelegate> delegate;
@property (nonatomic, assign, getter = isHorizontal) BOOL horizontal;
@property (nonatomic, assign) BOOL snapToRows;

@end
