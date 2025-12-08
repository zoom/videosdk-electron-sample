/*
    Copyright (c) 2011-2012 Masonry Team - https://github.com/Masonry

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/

#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>

@class ZMConstraintMaker;

static const NSLayoutPriority ZMLayoutPriorityDefaultMedium = 501;

typedef NS_OPTIONS(NSInteger, ZMAttribute) {
    ZMAttributeLeft = 1 << NSLayoutAttributeLeft,
    ZMAttributeRight = 1 << NSLayoutAttributeRight,
    ZMAttributeTop = 1 << NSLayoutAttributeTop,
    ZMAttributeBottom = 1 << NSLayoutAttributeBottom,
    ZMAttributeLeading = 1 << NSLayoutAttributeLeading,
    ZMAttributeTrailing = 1 << NSLayoutAttributeTrailing,
    ZMAttributeWidth = 1 << NSLayoutAttributeWidth,
    ZMAttributeHeight = 1 << NSLayoutAttributeHeight,
    ZMAttributeCenterX = 1 << NSLayoutAttributeCenterX,
    ZMAttributeCenterY = 1 << NSLayoutAttributeCenterY,
    ZMAttributeBaseline = 1 << NSLayoutAttributeBaseline,
};

/**
 *  An immutable tuple which stores the view and the related NSLayoutAttribute.
 *  Describes part of either the left or right hand side of a constraint equation
 */
@interface ZMViewAttribute : NSObject

/**
 *  The view which the reciever relates to. Can be nil if item is not a view.
 */
@property (nonatomic, assign, readonly) NSView *view;

/**
 *  The item which the reciever relates to.
 */
@property (nonatomic, assign, readonly) id item;

/**
 *  The attribute which the reciever relates to
 */
@property (nonatomic, assign, readonly) NSLayoutAttribute layoutAttribute;

/**
 *  Convenience initializer.
 */
- (id)initWithView:(NSView *)view layoutAttribute:(NSLayoutAttribute)layoutAttribute;

/**
 *  The designated initializer.
 */
- (id)initWithView:(NSView *)view item:(id)item layoutAttribute:(NSLayoutAttribute)layoutAttribute;

/**
 *    Determine whether the layoutAttribute is a size attribute
 *
 *    @return    YES if layoutAttribute is equal to NSLayoutAttributeWidth or NSLayoutAttributeHeight
 */
- (BOOL)isSizeAttribute;

@end

/**
 *    Provides constraint maker block
 *  and convience methods for creating ZMViewAttribute which are view + NSLayoutAttribute pairs
 */
@interface NSView (ZMAdditions)

@property (nonatomic, retain) ZMConstraintMaker *make;

/**
 *    following properties return a new ZMViewAttribute with current view and appropriate NSLayoutAttribute
 */
@property (nonatomic, strong, readonly) ZMViewAttribute *zm_left;
@property (nonatomic, strong, readonly) ZMViewAttribute *zm_top;
@property (nonatomic, strong, readonly) ZMViewAttribute *zm_right;
@property (nonatomic, strong, readonly) ZMViewAttribute *zm_bottom;
@property (nonatomic, strong, readonly) ZMViewAttribute *zm_leading;
@property (nonatomic, strong, readonly) ZMViewAttribute *zm_trailing;
@property (nonatomic, strong, readonly) ZMViewAttribute *zm_width;
@property (nonatomic, strong, readonly) ZMViewAttribute *zm_height;
@property (nonatomic, strong, readonly) ZMViewAttribute *zm_centerX;
@property (nonatomic, strong, readonly) ZMViewAttribute *zm_centerY;
@property (nonatomic, strong, readonly) ZMViewAttribute *zm_baseline;
@property (nonatomic, copy, readonly) ZMViewAttribute *(^zm_attribute)(NSLayoutAttribute attr);

/**
 *    a key to associate with this view
 */
@property (nonatomic, strong) id zm_key;

/**
 *    Finds the closest common superview between this view and another view
 *
 *    @param    view    other view
 *
 *    @return    returns nil if common superview could not be found
 */
- (instancetype)zm_closestCommonSuperview:(NSView *)view;

/**
 *  Creates a ZMConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created ZMConstraints
 */
- (NSArray *)zm_makeConstraints:(void(NS_NOESCAPE ^)(ZMConstraintMaker *make))block NS_DEPRECATED_MAC(10.9, 10.9,"Use -zm_makeConstraints instead");
- (NSArray *)zm_makeConstraints;

/**
 *  Creates a ZMConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing.
 *  If an existing constraint exists then it will be updated instead.
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created/updated ZMConstraints
 */
- (NSArray *)zm_updateConstraints:(void(NS_NOESCAPE ^)(ZMConstraintMaker *make))block NS_DEPRECATED_MAC(10.9, 10.9,"Use -zm_updateConstraints instead");
- (NSArray *)zm_updateConstraints;

/**
 *  Creates a ZMConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing.
 *  All constraints previously installed for the view will be removed.
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created/updated ZMConstraints
 */
- (NSArray *)zm_remakeConstraints:(void(NS_NOESCAPE ^)(ZMConstraintMaker *make))block NS_DEPRECATED_MAC(10.9, 10.9,"Use -zm_remakeConstraints instead");
- (NSArray *)zm_remakeConstraints;

- (void)zm_removeMakedConstraints;
@end



/**
 *  Enables Constraints to be created with chainable syntax
 *  Constraint can represent single NSLayoutConstraint (ZMViewConstraint)
 *  or a group of NSLayoutConstraints (ZMComposisteConstraint)
 */
@interface ZMConstraint : NSObject

// Chaining Support

/**
 *    Modifies the NSLayoutConstraint constant,
 *  only affects ZMConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeTop, NSLayoutAttributeLeft, NSLayoutAttributeBottom, NSLayoutAttributeRight
 */
- (ZMConstraint * (^)(NSEdgeInsets insets))insets;

/**
 *    Modifies the NSLayoutConstraint constant,
 *  only affects ZMConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeTop, NSLayoutAttributeLeft, NSLayoutAttributeBottom, NSLayoutAttributeRight
 */
- (ZMConstraint * (^)(CGFloat inset))inset;

/**
 *    Modifies the NSLayoutConstraint constant,
 *  only affects ZMConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeWidth, NSLayoutAttributeHeight
 */
- (ZMConstraint * (^)(CGSize offset))sizeOffset;

/**
 *    Modifies the NSLayoutConstraint constant,
 *  only affects ZMConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeCenterX, NSLayoutAttributeCenterY
 */
- (ZMConstraint * (^)(CGPoint offset))centerOffset;

/**
 *    Modifies the NSLayoutConstraint constant
 */
- (ZMConstraint * (^)(CGFloat offset))offset;

/**
 *  Modifies the NSLayoutConstraint constant based on a value type
 */
- (ZMConstraint * (^)(NSValue *value))valueOffset;

/**
 *    Sets the NSLayoutConstraint multiplier property
 */
- (ZMConstraint * (^)(CGFloat multiplier))multipliedBy;

/**
 *    Sets the NSLayoutConstraint multiplier to 1.0/dividedBy
 */
- (ZMConstraint * (^)(CGFloat divider))dividedBy;

/**
 *    Sets the NSLayoutConstraint priority to a float or NSLayoutPriority
 */
- (ZMConstraint * (^)(NSLayoutPriority priority))priority;

/**
 *    Sets the NSLayoutConstraint priority to ZMLayoutPriorityLow
 */
- (ZMConstraint * (^)(void))priorityLow;

/**
 *    Sets the NSLayoutConstraint priority to ZMLayoutPriorityMedium
 */
- (ZMConstraint * (^)(void))priorityMedium;

/**
 *    Sets the NSLayoutConstraint priority to ZMLayoutPriorityHigh
 */
- (ZMConstraint * (^)(void))priorityHigh;

/**
 *    Sets the constraint relation to NSLayoutRelationEqual
 *  returns a block which accepts one of the following:
 *    ZMViewAttribute, UIView, NSValue, NSArray
 *  see readme for more details.
 */
- (ZMConstraint * (^)(id attr))equalTo;
//@property (nonatomic, copy) ZMConstraint * (^equalTo)(id attr);

/**
 *    Sets the constraint relation to NSLayoutRelationGreaterThanOrEqual
 *  returns a block which accepts one of the following:
 *    ZMViewAttribute, UIView, NSValue, NSArray
 *  see readme for more details.
 */
- (ZMConstraint * (^)(id attr))greaterThanOrEqualTo;

/**
 *    Sets the constraint relation to NSLayoutRelationLessThanOrEqual
 *  returns a block which accepts one of the following:
 *    ZMViewAttribute, UIView, NSValue, NSArray
 *  see readme for more details.
 */
- (ZMConstraint * (^)(id attr))lessThanOrEqualTo;

- (ZMConstraint *)with;
- (ZMConstraint *)and;

/**
 *    Creates a new ZMCompositeConstraint with the called attribute and reciever
 */
- (ZMConstraint *)left;
- (ZMConstraint *)top;
- (ZMConstraint *)right;
- (ZMConstraint *)bottom;
- (ZMConstraint *)leading;
- (ZMConstraint *)trailing;
- (ZMConstraint *)width;
- (ZMConstraint *)height;
- (ZMConstraint *)centerX;
- (ZMConstraint *)centerY;
- (ZMConstraint *)baseline;


/**
 *    Sets the constraint debug name
 */
- (ZMConstraint * (^)(id key))key;

// NSLayoutConstraint constant Setters
// for use outside of zm_updateConstraints/zm_makeConstraints blocks

/**
 *    Modifies the NSLayoutConstraint constant,
 *  only affects ZMConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeTop, NSLayoutAttributeLeft, NSLayoutAttributeBottom, NSLayoutAttributeRight
 */
- (void)setInsets:(NSEdgeInsets)insets;

/**
 *    Modifies the NSLayoutConstraint constant,
 *  only affects ZMConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeTop, NSLayoutAttributeLeft, NSLayoutAttributeBottom, NSLayoutAttributeRight
 */
- (void)setInset:(CGFloat)inset;

/**
 *    Modifies the NSLayoutConstraint constant,
 *  only affects ZMConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeWidth, NSLayoutAttributeHeight
 */
- (void)setSizeOffset:(CGSize)sizeOffset;

/**
 *    Modifies the NSLayoutConstraint constant,
 *  only affects ZMConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeCenterX, NSLayoutAttributeCenterY
 */
- (void)setCenterOffset:(CGPoint)centerOffset;

/**
 *    Modifies the NSLayoutConstraint constant
 */
- (void)setOffset:(CGFloat)offset;

/**
 *  Whether or not to go through the animator proxy when modifying the constraint
 */
@property (nonatomic, copy, readonly) ZMConstraint *animator;

/**
 *  Activates an NSLayoutConstraint if it's supported by an OS.
 *  Invokes install otherwise.
 */
- (void)activate;

/**
 *  Deactivates previously installed/activated NSLayoutConstraint.
 */
- (void)deactivate;

/**
 *    Creates a NSLayoutConstraint and adds it to the appropriate view.
 */
- (void)install;

/**
 *    Removes previously installed NSLayoutConstraint
 */
- (void)uninstall;

@end




@interface ZMConstraint (AutoboxingSupport)

/**
 *  Aliases to corresponding relation methods (for shorthand macros)
 *  Also needed to aid autocompletion
 */
- (ZMConstraint * (^)(id attr))zm_equalTo;
- (ZMConstraint * (^)(id attr))zm_greaterThanOrEqualTo;
- (ZMConstraint * (^)(id attr))zm_lessThanOrEqualTo;

/**
 *  A dummy method to aid autocompletion
 */
- (ZMConstraint * (^)(id offset))zm_offset;

@end



/**
 *  Provides factory methods for creating ZMConstraints.
 *  Constraints are collected until they are ready to be installed
 *
 */
@interface ZMConstraintMaker : NSObject

/**
 *    The following properties return a new ZMViewConstraint
 *  with the first item set to the makers associated view and the appropriate ZMViewAttribute
 */
@property (nonatomic, strong, readonly) ZMConstraint *left;
@property (nonatomic, strong, readonly) ZMConstraint *top;
@property (nonatomic, strong, readonly) ZMConstraint *right;
@property (nonatomic, strong, readonly) ZMConstraint *bottom;
@property (nonatomic, strong, readonly) ZMConstraint *leading;
@property (nonatomic, strong, readonly) ZMConstraint *trailing;
@property (nonatomic, strong, readonly) ZMConstraint *width;
@property (nonatomic, strong, readonly) ZMConstraint *height;
@property (nonatomic, strong, readonly) ZMConstraint *centerX;
@property (nonatomic, strong, readonly) ZMConstraint *centerY;
@property (nonatomic, strong, readonly) ZMConstraint *baseline;

/**
 *  Returns a block which creates a new ZMCompositeConstraint with the first item set
 *  to the makers associated view and children corresponding to the set bits in the
 *  ZMAttribute parameter. Combine multiple attributes via binary-or.
 */
@property (nonatomic, copy, readonly) ZMConstraint *(^attributes)(ZMAttribute attrs);

/**
 *    Creates a ZMCompositeConstraint with type ZMCompositeConstraintTypeEdges
 *  which generates the appropriate ZMViewConstraint children (top, left, bottom, right)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) ZMConstraint *edges;

/**
 *    Creates a ZMCompositeConstraint with type ZMCompositeConstraintTypeSize
 *  which generates the appropriate ZMViewConstraint children (width, height)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) ZMConstraint *size;

/**
 *    Creates a ZMCompositeConstraint with type ZMCompositeConstraintTypeCenter
 *  which generates the appropriate ZMViewConstraint children (centerX, centerY)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) ZMConstraint *center;

/**
 *  Whether or not to check for an existing constraint instead of adding constraint
 */
@property (nonatomic, assign) BOOL updateExisting;

/**
 *  Whether or not to remove existing constraints prior to installing
 */
@property (nonatomic, assign) BOOL removeExisting;

/**
 *    initialises the maker with a default view
 *
 *    @param    view    any ZMConstraint are created with this view as the first item
 *
 *    @return    a new ZMConstraintMaker
 */
- (id)initWithView:(NSView *)view;

/**
 *    Calls install method on any ZMConstraints which have been created by this maker
 *
 *    @return    an array of all the installed ZMConstraints
 */
- (NSArray *)install;

- (ZMConstraint * (^)(dispatch_block_t))group;

@end



typedef NS_ENUM(NSUInteger, ZMAxisType) {
    ZMAxisTypeHorizontal,
    ZMAxisTypeVertical
};

@interface NSArray (ZMAdditions)

/**
 *  Creates a ZMConstraintMaker with each view in the callee.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing on each view
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to each view.
 *
 *  @return Array of created ZMConstraints
 */
- (NSArray *)zm_makeConstraints:(void (NS_NOESCAPE ^)(ZMConstraintMaker *make))block;

/**
 *  Creates a ZMConstraintMaker with each view in the callee.
 *  Any constraints defined are added to each view or the appropriate superview once the block has finished executing on each view.
 *  If an existing constraint exists then it will be updated instead.
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to each view.
 *
 *  @return Array of created/updated ZMConstraints
 */
- (NSArray *)zm_updateConstraints:(void (NS_NOESCAPE ^)(ZMConstraintMaker *make))block;

/**
 *  Creates a ZMConstraintMaker with each view in the callee.
 *  Any constraints defined are added to each view or the appropriate superview once the block has finished executing on each view.
 *  All constraints previously installed for the views will be removed.
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to each view.
 *
 *  @return Array of created/updated ZMConstraints
 */
- (NSArray *)zm_remakeConstraints:(void (NS_NOESCAPE ^)(ZMConstraintMaker *make))block;

/**
 *  distribute with fixed spacing
 *
 *  @param axisType     which axis to distribute items along
 *  @param fixedSpacing the spacing between each item
 *  @param leadSpacing  the spacing before the first item and the container
 *  @param tailSpacing  the spacing after the last item and the container
 */
- (void)zm_distributeViewsAlongAxis:(ZMAxisType)axisType withFixedSpacing:(CGFloat)fixedSpacing leadSpacing:(CGFloat)leadSpacing tailSpacing:(CGFloat)tailSpacing;

/**
 *  distribute with fixed item size
 *
 *  @param axisType        which axis to distribute items along
 *  @param fixedItemLength the fixed length of each item
 *  @param leadSpacing     the spacing before the first item and the container
 *  @param tailSpacing     the spacing after the last item and the container
 */
- (void)zm_distributeViewsAlongAxis:(ZMAxisType)axisType withFixedItemLength:(CGFloat)fixedItemLength leadSpacing:(CGFloat)leadSpacing tailSpacing:(CGFloat)tailSpacing;

@end



// ZMLayout Utilities.h
/**
 *  Allows you to attach keys to objects matching the variable names passed.
 *  view1.zm_key = @"view1", view2.zm_key = @"view2";
 *  is equivalent to:
 *  ZMAttachKeys(view1, view2);
 */
#define ZMAttachKeys(...)                                                         \
    {                                                                             \
        NSDictionary *keyPairs = NSDictionaryOfVariableBindings(__VA_ARGS__);     \
        for (id key in keyPairs.allKeys) {                                        \
            id obj = keyPairs[key];                                               \
            NSAssert([obj respondsToSelector:@selector(setZm_key:)],              \
                     @"Cannot attach zm_key to %@", obj);                         \
            [obj setZm_key:key];                                                  \
        }                                                                         \
}


/**
 *  Used to create object hashe
 */
#define ZM_NSUINT_BIT (CHAR_BIT * sizeof(NSUInteger))
#define ZM_NSUINTROTATE(val, howmuch) ((((NSUInteger)val) << howmuch) | (((NSUInteger)val) >> (ZM_NSUINT_BIT - howmuch)))
#define ZMBoxValue(value) _ZMBoxValue(@encode(__typeof__((value))), (value))
/**
 *  Given a scalar or struct value, wraps it in NSValue
 */
static inline id _ZMBoxValue(const char *type, ...) {
    va_list v;
    va_start(v, type);
    id obj = nil;
    if (strcmp(type, @encode(id)) == 0) {
        id actual = va_arg(v, id);
        obj = actual;
    } else if (strcmp(type, @encode(CGPoint)) == 0) {
        CGPoint actual = (CGPoint)va_arg(v, CGPoint);
        obj = [NSValue value:&actual withObjCType:type];
    } else if (strcmp(type, @encode(CGSize)) == 0) {
        CGSize actual = (CGSize)va_arg(v, CGSize);
        obj = [NSValue value:&actual withObjCType:type];
    } else if (strcmp(type, @encode(NSEdgeInsets)) == 0) {
        NSEdgeInsets actual = (NSEdgeInsets)va_arg(v, NSEdgeInsets);
        obj = [NSValue value:&actual withObjCType:type];
    } else if (strcmp(type, @encode(double)) == 0) {
        double actual = (double)va_arg(v, double);
        obj = [NSNumber numberWithDouble:actual];
    } else if (strcmp(type, @encode(float)) == 0) {
        float actual = (float)va_arg(v, double);
        obj = [NSNumber numberWithFloat:actual];
    } else if (strcmp(type, @encode(int)) == 0) {
        int actual = (int)va_arg(v, int);
        obj = [NSNumber numberWithInt:actual];
    } else if (strcmp(type, @encode(long)) == 0) {
        long actual = (long)va_arg(v, long);
        obj = [NSNumber numberWithLong:actual];
    } else if (strcmp(type, @encode(long long)) == 0) {
        long long actual = (long long)va_arg(v, long long);
        obj = [NSNumber numberWithLongLong:actual];
    } else if (strcmp(type, @encode(short)) == 0) {
        short actual = (short)va_arg(v, int);
        obj = [NSNumber numberWithShort:actual];
    } else if (strcmp(type, @encode(char)) == 0) {
        char actual = (char)va_arg(v, int);
        obj = [NSNumber numberWithChar:actual];
    } else if (strcmp(type, @encode(bool)) == 0) {
        bool actual = (bool)va_arg(v, int);
        obj = [NSNumber numberWithBool:actual];
    } else if (strcmp(type, @encode(unsigned char)) == 0) {
        unsigned char actual = (unsigned char)va_arg(v, unsigned int);
        obj = [NSNumber numberWithUnsignedChar:actual];
    } else if (strcmp(type, @encode(unsigned int)) == 0) {
        unsigned int actual = (unsigned int)va_arg(v, unsigned int);
        obj = [NSNumber numberWithUnsignedInt:actual];
    } else if (strcmp(type, @encode(unsigned long)) == 0) {
        unsigned long actual = (unsigned long)va_arg(v, unsigned long);
        obj = [NSNumber numberWithUnsignedLong:actual];
    } else if (strcmp(type, @encode(unsigned long long)) == 0) {
        unsigned long long actual = (unsigned long long)va_arg(v, unsigned long long);
        obj = [NSNumber numberWithUnsignedLongLong:actual];
    } else if (strcmp(type, @encode(unsigned short)) == 0) {
        unsigned short actual = (unsigned short)va_arg(v, unsigned int);
        obj = [NSNumber numberWithUnsignedShort:actual];
    }
    va_end(v);
    return obj;
}


/**
 *  Convenience auto-boxing macros for ZMConstraint methods.
 *
 *  Defining ZM_SHORTHAND_GLOBALS will turn on auto-boxing for default syntax.
 *  A potential drawback of this is that the unprefixed macros will appear in global scope.
 */
#define zm_equalTo(...)                 equalTo(ZMBoxValue((__VA_ARGS__)))
#define zm_greaterThanOrEqualTo(...)    greaterThanOrEqualTo(ZMBoxValue((__VA_ARGS__)))
#define zm_lessThanOrEqualTo(...)       lessThanOrEqualTo(ZMBoxValue((__VA_ARGS__)))
#define zm_offset(...)                  valueOffset(ZMBoxValue((__VA_ARGS__)))

//#ifndef ZMReleaseToNil
//#define ZMReleaseToNil(arg) if (arg) {[arg release]; arg = nil;}
//#endif

