//
//  mainMenuViewController.h
//  algorytms
//
//  Created by Blotenko on 06.04.2022.
//
/*!
@file mainMenuViewController.h
 
 @brief This is the header file where my mainMenu is contained.
 
 This file contains method for work with uitableview for types and uitextfield  and properties decalaration.

 */
#import <UIKit/UIKit.h>

/*!
 @class mainMenuViewController
 
 @brief The mainMenuViewController class
 
 @discussion    This class was designed and implemented for menu with tableView and textField.
 
 @superclass SuperClass: UIViewController\n
 @classdesign    No special design is applied here.
 @coclass    AppDelegate
 @helps It helps no other classes.
 @helper    No helper exists for this class.
 */
@interface mainMenuViewController : UIViewController<UITableViewDelegate,UITableViewDataSource>

@property (strong,nonatomic) IBOutlet  UITableView* typeTableView;



@end
