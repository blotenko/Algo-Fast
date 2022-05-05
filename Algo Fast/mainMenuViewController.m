//
//  mainMenuViewController.m
//  algorytms
//
//  Created by Blotenko on 06.04.2022.
//

#import "mainMenuViewController.h"
#import "resultsViewController.h"
@interface mainMenuViewController ()
@property (strong) NSNumber* selectedType;
@property (strong) NSMutableDictionary* types;
@property (strong) resultViewController* controller;


@property (strong, nonatomic) IBOutlet UITextField *textField;

@property (strong, nonatomic) IBOutlet UIButton *buttonResults;

@end

@implementation mainMenuViewController


- (void)viewDidLoad {
    [super viewDidLoad];
    self.typeTableView.delegate =self;
    self.typeTableView.dataSource=self;
    self.textField.delegate = self;
    // Do any additional setup after loading the view.
   
}
static NSString *gCellIdentifier = @"TextTypePopoverTableViewCell";

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 2;
}

-(UITableViewCell*)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell=[[UITableViewCell alloc]initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"cell"];
    if(indexPath.row == 0){
        cell.textLabel.text = @"String";
    }
    else if(indexPath.row == 1){
        cell.textLabel.text = @"Integer";
    }
    
    NSNumber* TypeKey =  [NSNumber numberWithInteger: indexPath.row];
    if (self.selectedType
        && [TypeKey isEqualToNumber: self.selectedType])
        cell.accessoryType = UITableViewCellAccessoryCheckmark;
    else
        cell.accessoryType = UITableViewCellAccessoryNone;
    return cell;
}

/*!
    This method prepare the result View controller with starting function with mass like a param
 */
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([[segue destinationViewController] isKindOfClass:resultViewController
         .class])
    {
        self.navigationController.delegate = self;
        if([self.selectedType intValue] == 0){
            [(resultViewController*)[segue destinationViewController] setResult:self.textField.text];
        }
        else if([self.selectedType intValue] == 1)
        {
            [(resultViewController*)[segue destinationViewController] setResultInt:self.textField.text];
        }
        [(resultViewController*)[segue destinationViewController] setDelegate:self];
    }
}




-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    self.selectedType = [NSNumber numberWithInteger: indexPath.row];
    self.textField.text = @"";
    [tableView reloadData];
}

- (BOOL)textFieldShouldBeginEditing:(UITextField *)textField
{
    if(self.selectedType == 0) return NO;
return YES;
}



- (void)textFieldDidBeginEditing:(UITextField *)textField
{
    [self.textField becomeFirstResponder];
    self.textField.text = @"" ;
    
}
- (BOOL)textFieldShouldClear:(UITextField *)textField
{
   // self.applyButton.enabled = NO;
    return NO;
}

-(BOOL)textFieldShouldReturn:(UITextField *)textField{
    [textField resignFirstResponder];
    self.textField.endOfDocument;
    [self updateTextFeildControl];
    return YES;
}

- (void) updateTextFeildControl
{
    [_textField setTextAlignment: NSTextAlignmentCenter];
    //_textField.placeholder  = @"vlad blotenko";
}


-(NSString*)returnString
{
    return self.textField.text;
}

@end
