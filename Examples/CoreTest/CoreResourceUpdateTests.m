//
//  CoreResourceUpdateTests.m
//  CoreTest
//
//  Created by Mike Laurence on 1/19/10.
//  Copyright 2010 Mike Laurence. All rights reserved.
//

#import "CoreResourceTestCase.h"

@interface CoreResourceUpdateTests : CoreResourceTestCase {}
@end

@implementation CoreResourceUpdateTests

- (void) testUpdateWithDictionary {
    [self loadArtist:0];
    NSDictionary* updateDict = [[self artistDataJSON:@"artists.0.update"] JSONValue];
    
    Artist* artist = (Artist*)[[Artist findLocal:[NSNumber numberWithInt:0]] resource];
    [artist update:updateDict];
    
    GHAssertEqualStrings(artist.name, @"Peter B. Gabriel", nil);
    GHAssertEqualStrings(artist.summary, @"Peter Brian Gabriel is a musician and songwriter.", nil);
}

//- (void) testShouldUpdateWithDictionary { GHFail(nil); }

@end
