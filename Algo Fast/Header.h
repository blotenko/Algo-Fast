//
//  Header.h
//  Algo Fast
//
//  Created by Blotenko on 05.05.2022.
//

#ifndef Header_h
#define Header_h


/**
@mainpage Программа для бачення швидкості виповнення алгоритмів сортування для  певного набору данних для ios приладів
 
 Алгоритми реалізовані мною на с++, а інтерфейс на objective-c з невиликою прослойкою з objective-c++ та виористання storyboard для розробки дизайну
 
 Реазовані алгоритми:
 - bubbleSort
 -  insertionSort
 - mergeSort
 - mergeSort
 - quickSort

 Состоит из следующих частей:
 - @ref mainMenuViewController.h  - обрання типу данних та заповнення масиву
 - @ref resultsViewController.h -  перегляд швидкості та результату сортування та також можливість переглянути код кожного алгоритму

 При  розробці було викорастонно  паттерни проетування, такі  як:
 - Strategy - @ref algoSort -  для реалізації алгоритмів, з можливістю заміни реалізації без зміни клієнтського коду
 - AbstractFactory -для побудови стандартних реалізацій певних алгоритмів
 - Builder - для побудови складних алгоритмів, які складаються з багатьох частин
 - Adapter - з метою використання бібліотечних реалізацій алгоритмів

 Також були реалізовані XCTest:
 -  тести розробленні apple для objective-c та за допомогою перейменування на .mm покривають і с++ файли
 
 Тести покривають реалізацію алгоритмів та роботу інтерфейсу на розличних ios приладах
*/
 



#endif /* Header_h */
