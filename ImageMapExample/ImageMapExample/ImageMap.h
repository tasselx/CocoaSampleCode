/*
     File: ImageMap.h
 Abstract: image map widget
  Version: 1.1
 
 Disclaimer: IMPORTANT:  This Apple software is supplied to you by Apple
 Inc. ("Apple") in consideration of your agreement to the following
 terms, and your use, installation, modification or redistribution of
 this Apple software constitutes acceptance of these terms.  If you do
 not agree with these terms, please do not use, install, modify or
 redistribute this Apple software.
 
 In consideration of your agreement to abide by the following terms, and
 subject to these terms, Apple grants you a personal, non-exclusive
 license, under Apple's copyrights in this original Apple software (the
 "Apple Software"), to use, reproduce, modify and redistribute the Apple
 Software, with or without modifications, in source and/or binary forms;
 provided that if you redistribute the Apple Software in its entirety and
 without modifications, you must retain this notice and the following
 text and disclaimers in all such redistributions of the Apple Software.
 Neither the name, trademarks, service marks or logos of Apple Inc. may
 be used to endorse or promote products derived from the Apple Software
 without specific prior written permission from Apple.  Except as
 expressly stated in this notice, no other rights or licenses, express or
 implied, are granted by Apple herein, including but not limited to any
 patent rights that may be infringed by your derivative works or by other
 works in which the Apple Software may be incorporated.
 
 The Apple Software is provided by Apple on an "AS IS" basis.  APPLE
 MAKES NO WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION
 THE IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS
 FOR A PARTICULAR PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND
 OPERATION ALONE OR IN COMBINATION WITH YOUR PRODUCTS.
 
 IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL
 OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 INTERRUPTION) ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION,
 MODIFICATION AND/OR DISTRIBUTION OF THE APPLE SOFTWARE, HOWEVER CAUSED
 AND WHETHER UNDER THEORY OF CONTRACT, TORT (INCLUDING NEGLIGENCE),
 STRICT LIABILITY OR OTHERWISE, EVEN IF APPLE HAS BEEN ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.
 
 Copyright (C) 2011 Apple Inc. All Rights Reserved.
 
 */

#import <Cocoa/Cocoa.h>

@interface ImageMap : NSView <NSXMLParserDelegate> {

    NSImage *image;

    SEL action;
    id target;

    NSMutableArray *hotSpotInfo;
    NSMutableArray *hotSpotPaths;

    BOOL hasDefault;
    id defaultInfo;

    NSUInteger selectedHotSpotIndex;
    BOOL isCurrentlySelected;
    NSColor *selectedHotSpotColor;

    BOOL hotSpotsVisible;
    NSColor *hotSpotsVisibleColor;

    NSCompositingOperation hotSpotCompositeOperation;

    // rollover highlighting support
    BOOL rolloverHighlighting;
    NSColor *rolloverHotSpotColor;
    BOOL windowAcceptsMouseMovedEvents;
    NSInteger rolloverHotSpotIndex;
    NSTrackingRectTag rolloverTrackingRectTag;

    // html client-side image map format support
    BOOL isHTMLImageMap;
    NSString *HTMLImageMapName;
    BOOL parsingHTMLMapElement;

}

@property (nonatomic, retain) NSImage *image;
@property (nonatomic, assign) id target;
@property (nonatomic, readwrite) SEL action;
@property (nonatomic, readwrite) BOOL hasDefault;
@property (nonatomic, assign) id defaultInfo;
@property (nonatomic, readwrite) BOOL rolloverHighlighting;
@property (nonatomic, readwrite) BOOL hotSpotsVisible;
@property (nonatomic, retain) NSColor *selectedHotSpotColor;
@property (nonatomic, retain) NSColor *rolloverHotSpotColor;
@property (nonatomic, readwrite) NSCompositingOperation hotSpotCompositeOperation;

- (void)addHotSpotForRect:(NSRect)rect info:(id)info ;
- (void)addHotSpotForCircle:(NSPoint)center radius:(float)radius info:(id)info ;
- (void)addHotSpotForPolygon:(NSPoint *)points count:(NSUInteger)count info:(id)info;

- (void)setHotSpotsFromImageMapNamed:(NSString *)name inHTMLFile:(NSString *)path;
- (void)setImageAndHotSpotsFromImageAndImageMapNamed:(NSString *)name;

- (id)selectedHotSpotInfo;

@end
