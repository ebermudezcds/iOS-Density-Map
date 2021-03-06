# iOS Density Map

[![Version](https://img.shields.io/cocoapods/v/iOS-Density-Map.svg?style=flat)](http://cocoapods.org/pods/iOS-Density-Map)
[![Carthage Compatible](https://img.shields.io/badge/Carthage-compatible-4BC51D.svg?style=flat)](https://github.com/Carthage/Carthage)
[![License](https://img.shields.io/cocoapods/l/iOS-Density-Map.svg?style=flat)](http://cocoapods.org/pods/iOS-Density-Map)
[![Platform](https://img.shields.io/cocoapods/p/iOS-Density-Map.svg?style=flat)](http://cocoapods.org/pods/iOS-Density-Map)
[![Build Status](https://travis-ci.org/enriquebk/iOS-Density-Map.svg?branch=master)](https://travis-ci.org/enriquebk/iOS-Density-Map)

By using OpenGL ES, iOS Density Map allows you to efficiently render thousands of particles over a map.

iOS Density Map has two main components:

**GLParticlesRender:** Renders all the particles in a `eaglcontext`. Basically it renders groups of particles with a specific style (`GLParticleStyle`).

**GLDensityMapView:** Provides the `eaglcontext` and the particles groups info for the `GLParticlesRender`. The `GLDensityMapView` provides  a number of properties and blocks that needs to be overwritten in order to display the particles.

## Installation

iOS-Density-Map is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod 'iOS-Density-Map'
```

Then import the `GLDensityMap.h` header file:

```Objective-c
#import <GLDensityMap.h>
```

## Usage

```Objective-c
- (void)setupDensityMapView{
    
    //Set the number of particles styles (style groups).
    self.densityMapView.styleGroupsCount = 1;
    
    //Returns the `GLParticleStyle` for each group.
    self.densityMapView.styleForStyleGroup = ^GLParticleStyle(GLStyleGroupIndex groupIndex) {
        GLParticleStyle style = {
            .radius = 7,
            .blurFactor = 0.95,
            .r = 255,
            .g = 130,
            .b = 0,
            .opacity = 0.45,
        };
        return style;
    };
    
    __weak ViewController *wself = self;
    
    //Returns the number of particles for each group.
    self.densityMapView.particlesCountForStyleGroup = ^uint(GLStyleGroupIndex groupIndex) {
        return (int)wself.locations.count;
    };
    
    //Retruns the x,y position for each particle
    self.densityMapView.positionForParticle = ^CGPoint(GLParticleIndex pointIndex, GLStyleGroupIndex groupIndex) {
        return  [wself.mapView convertCoordinate:wself.locations[pointIndex].coordinate
                                   toPointToView:wself.view];
    };
}
```

## Example

![](https://raw.githubusercontent.com/enriquebk/iOS-Density-Map/master/Screenshot.png)

## Author

Enrique Bermúdez, ebermudez.ing@gmail.com

## License

iOS Density Map is available under the MIT license. See the LICENSE file for more info.


