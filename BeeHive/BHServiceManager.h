/**
 * Created by BeeHive.
 * Copyright (c) 2016, Alibaba, Inc. All rights reserved.
 *
 * This source code is licensed under the GNU GENERAL PUBLIC LICENSE.
 * For the full copyright and license information,please view the LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>

@class BHContext;

@interface BHServiceManager : NSObject

@property (nonatomic, assign) BOOL  enableException;

+ (instancetype)sharedManager;

- (void)registerLocalServices;

- (void)registerService:(Protocol *)service implClass:(Class)implClass;

- (id)createService:(Protocol *)service;
- (id)createService:(Protocol *)service withServiceName:(NSString *)serviceName;
- (id)createService:(Protocol *)service withServiceName:(NSString *)serviceName shouldCache:(BOOL)shouldCache;

- (id)getServiceInstanceFromServiceName:(NSString *)serviceName;
- (void)removeServiceWithServiceName:(NSString *)serviceName;
#pragma mark - # edit to publick

/**
 根据协议获取类名
 协议中可能有类方法
 @param service service Protocol
 @return Class
 */
- (Class)serviceImplClass:(Protocol *)service;
@end
