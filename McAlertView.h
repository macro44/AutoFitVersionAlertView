//
//  McAlertView.h
//  ZJFramework
//
//  Created by Macro on 16/6/20.
//  Copyright © 2016年 别问我是谁. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef void(^McAlertViewResponseBlock)(NSInteger index, id responseData, NSArray * textFieldArray);

typedef NS_ENUM(NSInteger, McAlertViewType) {
    McAlertViewTypeAlertView,
    McAlertViewTypeActionSheet,
    McAlertViewTypeTextFieldAlertView
};

@interface McAlertView : NSObject<UIAlertViewDelegate,UIActionSheetDelegate>

@property (nonatomic, copy) McAlertViewResponseBlock responseBlock;

+ (instancetype)shareInstance;

/**
 *  初始化alertView（当没有输入框时建议用此方法----没有，没有）
 *
 *  @param target  显示的主控制器
 *  @param type    alertView的类型
 *  @param title   alertView的标题
 *  @param message alertView的内容
 *  @param array   按钮/选项的名称数组(建议使用[@"取消", @"确定" ,...]的形式 )
 *  @param block   点击按钮的响应block(当为alertView的形式的时候，index = 0时候，表示第一个，index = 1，表示第二个按钮,...)
 *                 (当为 actionSheet的时候，index == 0时，仍表示取消，index = 1，表示第一个非取消按钮....)
 */
- (void)alertViewTarget:(id)target
          alertViewType:(McAlertViewType)type
                  title:(NSString*)title
                message:(NSString*)message
           actionTitles:(NSArray*)array
clickButtonResponseBlock:(McAlertViewResponseBlock)block;

/**
 *  初始化alertView(当有输入框时建议用此方法----有)
 *
 *  @param target       显示的主控制器
 *  @param type         alertView的类型
 *  @param title        alertView的标题
 *  @param message      alertView的内容
 *  @param array        按钮/选项的名称数组(建议使用[@"取消", @"确定" ,...]的形式 )
 *  @param placeHolders 如果存在输入框，则输入框的默认值
 *  @param block        点击按钮的响应block(当为alertView的形式的时候，index = 0时候，表示第一个，index = 1，表示第二个按钮,...)
 *                      (当为 actionSheet的时候，index == 0时，仍表示取消，index = 1，表示第一个非取消按钮....)
 */
- (void)alertViewTarget:(id)target
                      alertViewType:(McAlertViewType)type
                              title:(NSString*)title
                            message:(NSString*)message
                       actionTitles:(NSArray*)array
              textFieldPlaceHolders:(NSArray*)placeHolders
            textFieldsArrayResponse:(void(^)(NSArray*))textFieldBlock
           clickButtonResponseBlock:(McAlertViewResponseBlock)block;

@end
