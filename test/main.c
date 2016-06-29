//
//  main.c
//  test
//
//  Created by Axis on 6/28/16.
//  Copyright © 2016 Axis. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int a;
    printf("%d", ({typeof(a) b=10; b;}));
    return 0;
}
