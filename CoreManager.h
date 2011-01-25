//
//  CoreResource.h
//  CoreResource
//
//  Created by Mike Laurence on 12/24/09.
//  Copyright Mike Laurence 2010. All rights reserved.
//

#import "ASIHTTPRequest.h"
#import "CoreRequest.h"

@class CoreResource;

@protocol CoreRequestConfigurationDelegate <NSObject>
- (void) configureRequest:(CoreRequest*)request forAction:(NSString*)action onResource:(CoreResource*)resource;
@end

@interface CoreManager : NSObject {
    id<CoreRequestConfigurationDelegate> requestConfigurationDelegate;
    NSManagedObjectModel *managedObjectModel;
    NSManagedObjectContext *managedObjectContext;
    NSPersistentStoreCoordinator *persistentStoreCoordinator;
    
    NSOperationQueue *requestQueue;
    NSOperationQueue *deserialzationQueue;
    
    NSString *remoteSiteURL;
    
    // Default setting for whether or not to get data from within the bundle (instead of performing remote HTTP requests)
    BOOL useBundleRequests;

    // Artificial delay added for bundle requests
    float bundleRequestDelay;

    NSDateFormatter *defaultDateParser;
    
    NSMutableDictionary *entityDescriptions;
    NSMutableDictionary *modelProperties;
    NSMutableDictionary *modelRelationships;
    NSMutableDictionary *modelAttributes;
    
    int logLevel;
}

@property (nonatomic, retain) id<CoreRequestConfigurationDelegate> requestConfigurationDelegate;
@property (nonatomic, retain, readonly) NSManagedObjectModel *managedObjectModel;
@property (nonatomic, retain, readonly) NSManagedObjectContext *managedObjectContext;
@property (nonatomic, retain, readonly) NSPersistentStoreCoordinator *persistentStoreCoordinator;

@property (nonatomic, retain) NSOperationQueue *requestQueue;
@property (nonatomic, retain) NSOperationQueue *deserialzationQueue;

@property (nonatomic, retain) NSString *remoteSiteURL;
@property (nonatomic, assign) BOOL useBundleRequests;
@property (nonatomic, assign) float bundleRequestDelay;

@property (nonatomic, retain) NSDateFormatter *defaultDateParser;

@property (nonatomic, retain) NSMutableDictionary *entityDescriptions;
@property (nonatomic, retain) NSMutableDictionary *modelProperties;
@property (nonatomic, retain) NSMutableDictionary *modelRelationships;
@property (nonatomic, retain) NSMutableDictionary *modelAttributes;

@property (nonatomic, assign) int logLevel;

+ (CoreManager*) main;
+ (void) setMain: (CoreManager*)newMain;

- (id) initWithOptions:(NSDictionary*)options;
- (NSString*)applicationDocumentsDirectory;

#pragma mark -
#pragma mark Networking
- (void) enqueueRequest:(ASIHTTPRequest*)request;
- (void) configureRequest:(CoreRequest*)request forAction:(NSString*)action onResource:(CoreResource*)resource;

#pragma mark -
#pragma mark Alerts & Errors
+ (void) alertWithError:(NSError*)error;
+ (void) alertWithTitle:(NSString*)title andMessage:(NSString*)message;
+ (void) logCoreDataError:(NSError*)error;

#pragma mark -
#pragma mark Core Data
- (void) save;

/**
    Creates and returns a new NSManagedObjectContext pointing to the main persistent store
*/
- (NSManagedObjectContext*) newContext;

- (void) mergeContext:(NSNotification*)notification;

@end

