//
//  PZMRichKeyButton.h
//  Prism
//
//  Created by Cooper.Chen on 2025/4/11.
//

#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>

@interface PZMRichKeyButton: NSButton

- (void)commonInit NS_REQUIRES_SUPER; // to override
- (void)setAction:(SEL)selector forKeyCode:(NSInteger)keyCode;//!< Custom an action for a specified keycode
- (void)removeActionForKeyCode:(NSInteger)keyCode;
- (void)addClickKey:(NSInteger)keyCode;
- (void)removeClickKey:(NSInteger)keyCode;

@property (assign, nonatomic) IBInspectable BOOL dropDown; //!< Make this property to YES, if button will trigger a Menu popup
@property (assign, nonatomic) IBInspectable BOOL popUp; //!< Make this property to YES, if button will trigger a Menu popup

@property (nonatomic , assign) BOOL zmEnable;

//private
@property (nonatomic, strong) NSMutableDictionary <NSNumber *, NSString *> *richActions;
@property (nonatomic, strong) NSMutableArray <NSNumber *> *clickKeys;

@end
