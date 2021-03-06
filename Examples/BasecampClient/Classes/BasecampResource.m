//
//  BasecampResource.m
//  BasecampClient
//
//  Created by Mike Laurence on 3/6/10.
//  Copyright 2010 Mike Laurence.
//

#import "BasecampResource.h"
#import "NSString+InflectionSupport.h"


@implementation BasecampResource

+ (NSString*) localNameForRemoteField:(NSString*)field {
    return [field camelize];
}

+ (NSString*) remoteNameForLocalField:(NSString*)field {
    return [field deCamelizeWith:@"_"];
}

// Remove nesting from JSON response
+ (NSArray*) dataCollectionFromDeserializedCollection:(id)deserializedCollection {

    NSArray* collectionArray = [[[deserializedCollection objectAtIndex:0] allValues] objectAtIndex:0];

    NSMutableArray* array = [NSMutableArray arrayWithCapacity:[collectionArray count]];
    for (NSDictionary* dict in collectionArray)
        [array addObject:[[dict allValues] objectAtIndex:0]];
    
    return array;
}

@end
