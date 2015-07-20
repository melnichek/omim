//
//  MWMRoutePreview.h
//  Maps
//
//  Created by Ilya Grechuhin on 21.07.15.
//  Copyright (c) 2015 MapsWithMe. All rights reserved.
//

#import "UIKitCategories.h"

@interface MWMRoutePreview : SolidTouchView

@property (weak, nonatomic) IBOutlet UILabel * status;
@property (weak, nonatomic) IBOutlet UIButton * walk;
@property (weak, nonatomic) IBOutlet UIButton * drive;

@end