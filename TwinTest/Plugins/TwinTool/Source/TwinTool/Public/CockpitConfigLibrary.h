// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CockpitConfigLibrary.generated.h"

/**
 * 
 */
UCLASS()
class TWINTOOL_API UCockpitConfigLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

    //-- 基础读取函数 --//
public:
    /**
     * 从自定义配置文件中读取一个布尔值
     * @param ConfigFileName 不包含后缀的ini文件名，例如 "GameSettings"
     * @param Section 配置节名，"/Script/[MyModule].[ConfigClassName]", 例如: "/Script/MyProject.CockpitSettings"
     * @param Key 键名, 如 "bShowHud"
     * @param Value 输出值
     * @return 是否成功读取
     */
    UFUNCTION(BlueprintCallable, Category = "Config|Custom")
    static bool ReadConfigBool(const FString& ConfigFileName, const FString& Section, const FString& Key, bool& Value);

    /**
     * 从自定义配置文件中读取一个整型值
     */
    UFUNCTION(BlueprintCallable, Category = "Config|Custom")
    static bool ReadConfigInt(const FString& ConfigFileName, const FString& Section, const FString& Key, int32& Value);

    /**
     * 从自定义配置文件中读取一个浮点值
     */
    UFUNCTION(BlueprintCallable, Category = "Config|Custom")
    static bool ReadConfigFloat(const FString& ConfigFileName, const FString& Section, const FString& Key, float& Value);

    /**
     * 从自定义配置文件中读取一个字符串值
     */
    UFUNCTION(BlueprintCallable, Category = "Config|Custom")
    static bool ReadConfigString(const FString& ConfigFileName, const FString& Section, const FString& Key, FString& Value);

    /**
     * 从自定义配置文件中读取一个FVector值（格式: X=1.0 Y=2.0 Z=3.0）
     */
    UFUNCTION(BlueprintCallable, Category = "Config|Custom")
    static bool ReadConfigVector(const FString& ConfigFileName, const FString& Section, const FString& Key, FVector& Value);

    /**
     * 从自定义配置文件中读取一个FVector值（格式: X=1.0 Y=2.0 Z=3.0）
     */
    UFUNCTION(BlueprintCallable, Category = "Config|Custom")
    static bool ReadConfigRotator(const FString& ConfigFileName, const FString& Section, const FString& Key, FRotator& Value);

    //-- 基础写入函数 --//
public:
     /**
     * 写任意配置（字符串类型）（可选），写入后自动保存到 aved/Config下，支持运行时修改
     * 用户可以在打包后手动修改此文件！
     */
    UFUNCTION(BlueprintCallable, Category = "Config|Custom")
    static bool WriteConfig(const FString& ConfigFileName, const FString& Section, const FString& Key, const FString& Value);

    /**
     * 重载：写入布尔值
     */
    UFUNCTION(BlueprintCallable, Category = "Cockpit|Config")
    static bool WriteConfigBool(const FString& ConfigFileName, const FString& Section, const FString& Key, bool Value);

    /**
     * 重载：写入整数
     */
    UFUNCTION(BlueprintCallable, Category = "Cockpit|Config")
    static bool WriteConfigInt(const FString& ConfigFileName, const FString& Section, const FString& Key, int32 Value);

    /**
     * 重载：写入浮点数
     */
    UFUNCTION(BlueprintCallable, Category = "Cockpit|Config")
    static bool WriteConfigFloat(const FString& ConfigFileName, const FString& Section, const FString& Key, float Value);

    /**
     * 重载：写入Vector
     */
    UFUNCTION(BlueprintCallable, Category = "Cockpit|Config")
    static bool WriteConfigVector(const FString& ConfigFileName, const FString& Section, const FString& Key, const FVector& Value);

    /**
     * 重载：写入Rotator
     */
    UFUNCTION(BlueprintCallable, Category = "Cockpit|Config")
    static bool WriteConfigRotator(const FString& ConfigFileName, const FString& Section, const FString& Key, const FRotator& Value);

    //-- 工具函数：检查文件是否存在 --//
    /**
     * 检查CockpitConfig.ini是否存在（在Saved/Config下）
     */
    UFUNCTION(BlueprintPure, Category = "Cockpit|Config")
    static bool IsConfigFileExists(const FString& ConfigFileName);

    /**
     * 强制重新加载配置（当外部修改了ini文件后调用）
     */
    UFUNCTION(BlueprintCallable, Category = "Cockpit|Config")
    static void ReloadConfig(const FString& ConfigFileName);
};
