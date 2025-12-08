//
//  ZMHtmlNodeColor.h
//  ZoomKit
//
//  Created by Francis Zhuo on 6/22/21.
//

NS_ASSUME_NONNULL_BEGIN

#ifndef ZMHtmlNodeColor_H
#define ZMHtmlNodeColor_H

typedef struct {
    NSInteger color;
    NSInteger darkColor;
    float alpha;
    float darkAlpha;
}ZMHtmlNodeColor;

NS_INLINE ZMHtmlNodeColor ZMMakeNodeColor(NSInteger color, float alpha, NSInteger darkColor, float darkAlpha) {
    
    ZMHtmlNodeColor c;
    c.color=color;
    c.alpha=alpha;
    c.darkColor=darkColor;
    c.darkAlpha=darkAlpha;
    
    return c;
}
#endif


NS_ASSUME_NONNULL_END
