//
//  UIAlertController+XLGExtension.h
//  SharenGo
//  Notes：UIAlertController封装
//
//  Created by Jason_hzb on 2018/5/7.
//  Copyright © 2018年 小灵狗出行. All rights reserved.
//

#import <UIKit/UIKit.h>

#if TARGET_OS_IOS
typedef void (^UIAlertControllerPopoverPresentationControllerBlock) (UIPopoverPresentationController * __nonnull popover);
#endif
typedef void (^UIAlertControllerCompletionBlock) (UIAlertController * __nonnull controller, UIAlertAction * __nonnull action, NSInteger buttonIndex);

@interface UIAlertController (XLGExtension)

@property (readonly, nonatomic) BOOL visible;
@property (readonly, nonatomic) NSInteger cancelButtonIndex;
@property (readonly, nonatomic) NSInteger firstOtherButtonIndex;
@property (readonly, nonatomic) NSInteger destructiveButtonIndex;

+ (UIAlertController * _Nonnull)alertWithTitle:(NSString * _Nullable)alertTitle
                                       message:(NSString * _Nullable)message
                                 okActionTitle:(NSString * _Nullable)okActionTitle
                                 okActionStyle:(UIAlertActionStyle)okActionStyle
                               okActionHandler:(void(^ _Nullable)(UIAlertAction * _Nonnull action))okActionHandler cancelActionTitle:(NSString * _Nullable)cancelActionTitle
                             cancelActionStyle:(UIAlertActionStyle)cancelActionStyle
                           cancelActionHandler:(void(^_Nullable)(UIAlertAction * _Nonnull action))cancelActionHandler;

+ (nonnull instancetype)showInViewController:(nonnull UIViewController *)viewController
                                   withTitle:(nullable NSString *)title
                                     message:(nullable NSString *)message
                              preferredStyle:(UIAlertControllerStyle)preferredStyle
                           cancelButtonTitle:(nullable NSString *)cancelButtonTitle
                      destructiveButtonTitle:(nullable NSString *)destructiveButtonTitle
                           otherButtonTitles:(nullable NSArray *)otherButtonTitles
#if TARGET_OS_IOS
          popoverPresentationControllerBlock:(nullable UIAlertControllerPopoverPresentationControllerBlock)popoverPresentationControllerBlock
#endif
                                    tapBlock:(nullable UIAlertControllerCompletionBlock)tapBlock;

+ (nonnull instancetype)showAlertInViewController:(nonnull UIViewController *)viewController
                                        withTitle:(nullable NSString *)title
                                          message:(nullable NSString *)message
                                cancelButtonTitle:(nullable NSString *)cancelButtonTitle
                           destructiveButtonTitle:(nullable NSString *)destructiveButtonTitle
                                otherButtonTitles:(nullable NSArray *)otherButtonTitles
                                         tapBlock:(nullable UIAlertControllerCompletionBlock)tapBlock;


+ (nonnull instancetype)showActionSheetInViewController:(nonnull UIViewController *)viewController
                                              withTitle:(nullable NSString *)title
                                                message:(nullable NSString *)message
                                      cancelButtonTitle:(nullable NSString *)cancelButtonTitle
                                 destructiveButtonTitle:(nullable NSString *)destructiveButtonTitle
                                      otherButtonTitles:(nullable NSArray *)otherButtonTitles
#if TARGET_OS_IOS
                     popoverPresentationControllerBlock:(nullable UIAlertControllerPopoverPresentationControllerBlock)popoverPresentationControllerBlock
#endif
                                               tapBlock:(nullable UIAlertControllerCompletionBlock)tapBlock;

@end
