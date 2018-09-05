//
//  GLDensityMapView.h
//  GLDensityMap
//
//  Created by Enrique Bermúdez on 3/15/18.
//  Copyright © 2018 Enrique Bermúdez. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GLParticlesRender.h"

@interface GLDensityMapView : UIView <GLParticlesRenderDelegate>

/**
 * Number of particles group styles.
 */
@property int styleGroupsCount;

/**
 * Called when rendering the GLDensityMapView. Retruns actual style of a style group.
 */
@property (nonnull) GLParticleStyle (^styleForStyleGroup)(GLStyleGroupIndex);

/**
 * Called when rendering the GLDensityMapView. Retruns the number of particles that with
 * be rendered witha given style group.
 */
@property (nonnull) uint (^particlesCountForStyleGroup)(GLStyleGroupIndex);

/**
 * Called when rendering the GLDensityMapView. Retruns the particle position(inside the view) of a
 * given particle inside a certain style group.
 */
@property (nonnull) CGPoint (^positionForParticle)(GLParticleIndex,GLStyleGroupIndex);

/**
 * Renders the density map.
 */
- (void)render;

@end
