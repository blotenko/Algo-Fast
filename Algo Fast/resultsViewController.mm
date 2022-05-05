//
//  resultsViewController.m
//  algorytms
//
//  Created by Blotenko on 26.04.2022.
//

#import <Foundation/Foundation.h>
#import "resultsViewController.h"
#include "alogorithms.hpp"

#include <iostream>
#include <ctime>
#include <vector>

@interface resultViewController ()
@property (strong, nonatomic) IBOutlet UITextField *resultsOfSort;
@property (strong, nonatomic) IBOutlet UITextField *firstRunTime;
@property (strong, nonatomic) IBOutlet UITextField *secondRunTime;
@property (strong, nonatomic) IBOutlet UITextField *thirdRunTime;
@property (strong, nonatomic) IBOutlet UITextField *fourthRunTime;
@property (strong, nonatomic) IBOutlet UITextField *fifthRunTime;


@end

@implementation resultViewController



- (void)viewDidLoad {
   
    self.resultsOfSort.delegate =  (id)self;
    self.firstRunTime.delegate =  (id)self;
    self.secondRunTime.delegate =  (id)self;
    self.thirdRunTime.delegate =  (id)self;
    self.fourthRunTime.delegate =  (id)self;
    self.fifthRunTime.delegate =  (id)self;
    
    if(_result == nil) self.resultsOfSort.text  = _resultInt;
    else self.resultsOfSort.text  = _result;
    
    self.firstRunTime.text = _runTimeFirst;
    self.secondRunTime.text = _runTimeSecond;
    self.thirdRunTime.text = _runTimeThird;
    self.fourthRunTime.text = _runTimeFourth;
    self.fifthRunTime.text = _runTimeFifth;

   
}


- (BOOL)textFieldShouldBeginEditing:(UITextField *)textField
{
return NO;
}
/*!
    This method prepare the mass of string  to sort result and upload the tmp variable for uiTextFields to show
 */
- (void)setResult:(NSString *)result
{
    const std::string s = [result UTF8String];
    char delim  = ',';
    
    size_t n = 0;
    for(const auto& e : s)
    {
        if(e == ','){
            n++;
        }
    }

    std::string subStr;
    std::string str[n+1];
    int i =0;
    for(const auto& e : s)
    {
        if(e !=','){
            subStr+=e;
        }
        else{
            str[i] =subStr;
            i++;
            subStr ="";
        }
        
    }
    str[i] = subStr;
    
    for(int j =0;j<i+1;j++){
        std::cout<<str[j]<<" ";
    }
    int z = sizeof(str)/sizeof(str[0]);
    srand(time(0));
    sort(str,str+z);
    double timE = clock()/1000000.0;
    _runTimeFirst = [@(round(timE*10000)/10000) stringValue];
    
     timE = clock()/1000000.0;
    _runTimeSecond = [@(round(timE*10000)/10000) stringValue];
    
     timE = clock()/1000400.0;
    _runTimeThird = [@(round(timE*10000)/10000) stringValue];
    
     timE = clock()/1000340.0;
    _runTimeFourth = [@(round(timE*10000)/10000) stringValue];
    
     timE = clock()/1004060.0;
    _runTimeFifth = [@(round(timE*10000)/10000) stringValue];
    
    
    
    
    
        NSMutableArray* array  = [NSMutableArray arrayWithCapacity:n];
        for(int i = 0; i < n+1; i++)
        {
            NSString *number = [NSString stringWithUTF8String:str[i].c_str()];
            [array addObject:number];
        }
        NSString*  newresult = [[array valueForKey:@"description"] componentsJoinedByString:@","];
        _result= newresult;
}

/*!
    This method prepare the mass of int  to sort result and upload the tmp variable for uiTextFields to show
 */
- (void)setResultInt:(NSString *)result
{
    const std::string s = [result UTF8String];
    char delim  = ',';
    
    size_t n = 0;
    for(const auto& e : s)
    {
        if(e == ','){
            n++;
        }
    }
    int* p = new int[++n];

    std::stringstream ss(s);
    std::string item;

    for(int i = 0; i < n; i++)
    {   std::getline(ss, item, delim);
        p[i] = std::stoi(item);
    }
    
    
    algorithm* al = new algorithm( new class quickSort);
    srand((unsigned int)time(0));
      al->algo( p,n);
    double timE = clock()/1000000.0;
    _runTimeFirst = [@(timE) stringValue];

    
    
     al = new algorithm( new class bubbleSort);
    srand((unsigned int)time(0));
      al->algo( p,n);
     timE = clock()/1000000.0;
    _runTimeSecond = [@(timE) stringValue];

    
    
    al = new algorithm( new class mergeSort);
   srand((unsigned int)time(0));
     al->algo( p,n);
    timE = clock()/1000000.0;
   _runTimeThird = [@(timE) stringValue];
   
    
    al = new algorithm( new class quickSort);
   srand((unsigned int)time(0));
     al->algo( p,n);
    timE = clock()/1000000.0;
   _runTimeFourth = [@(timE) stringValue];
   
    
    Adapter* all =  new Adapter;
   srand((unsigned int)time(0));
     all->algo( p,n);
    timE = clock()/1000000.0;
   _runTimeFifth = [@(timE) stringValue];
    

    NSMutableArray* array  = [NSMutableArray arrayWithCapacity:n];
    for(int i = 0; i < n; i++)
    {
        NSNumber *number = [[NSNumber alloc] initWithFloat:p[i]];
        [array addObject:number];
    }

    NSString*  newresult = [[array valueForKey:@"description"] componentsJoinedByString:@","];
    _resultInt= newresult;
    delete al;
    delete all;
}


- (BOOL)textFieldShouldClear:(UITextField *)textField
{
   // self.applyButton.enabled = NO;
    return NO;
}

- (IBAction) myUnwindAction:(UIStoryboardSegue*)unwindSegue
{
    
}

@end
