//
//  resultsViewController.h
//  algorytms
//
//  Created by Blotenko on 26.04.2022.
//
/*!
@file resultViewController.h
 
 @brief This is the header file where my resultView is contained.
 
 This file contains method for work with uittextFields for result  and properties decalaration.

 */
#ifndef resultsViewController_h
#define resultsViewController_h
#import <UIKit/UIKit.h>

@protocol mainMenuViewControllerDelegate <NSObject>
@required
-(NSString*)returnString;
@end


/*!
 @class resultViewController
 
 @brief The resultViewController class
 
 @discussion    This class was designed and implemented for menu with textFields.
 
 @superclass SuperClass: UIViewController\n
 @classdesign    No special design is applied here.
 @coclass    AppDelegate
 @helps It helps no other classes.
 @helper    No helper exists for this class.
 */
@interface resultViewController : UIViewController
@property (weak, nonatomic) NSString* result;
@property (weak, nonatomic) NSString* resultInt;
@property (weak, nonatomic) NSString* runTimeFirst;
@property (weak, nonatomic) NSString* runTimeSecond;
@property (weak, nonatomic) NSString* runTimeThird;
@property (weak, nonatomic) NSString* runTimeFourth;
@property (weak, nonatomic) NSString* runTimeFifth;


@property (weak) IBOutlet id<mainMenuViewControllerDelegate> delegate;
@end

#endif /* resultsViewController_h */
