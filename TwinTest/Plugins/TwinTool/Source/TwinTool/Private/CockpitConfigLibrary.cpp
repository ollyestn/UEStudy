// Fill out your copyright notice in the Description page of Project Settings.


#include "CockpitConfigLibrary.h"
#include "Misc/ConfigCacheIni.h"
#include "Misc/FeedbackContext.h"
#include "HAL/FileManager.h"
#include "Misc/Paths.h"

//YourProject/Saved/Config/WindowsEditor/Cockpit.ini     ← 编辑器下
//YourPackagedGame/Saved/Config/Windows/Cockpit.ini       ← 打包后可修改

// 获取运行时配置路径（优先使用 Saved/Config 下的可写路径）
static FString GetRuntimeConfigDirectory()
{
#if WITH_EDITOR
    return FPaths::ProjectSavedDir() + TEXT("Config/") + FPlatformProperties::IniPlatformName() + TEXT("Editor/");
#else
    return FPaths::ProjectSavedDir() + TEXT("Config/") + FPlatformProperties::IniPlatformName() + TEXT("/");
#endif
}

static FString GetConfigPath(const FString& ConfigFileName)
{
    // 格式：Saved/Config/PlatformName/ConfigFileName.ini
    FString ConfigDir = GetRuntimeConfigDirectory();
    IFileManager::Get().MakeDirectory(*ConfigDir, true);

    return ConfigDir + ConfigFileName + TEXT(".ini");
}

// 确保目录存在
static void EnsureConfigDirectoryExists()
{
    const FString ConfigDir = FPaths::GetPath(GetRuntimeConfigDirectory());
    IFileManager::Get().MakeDirectory(*ConfigDir, true);
}


bool UCockpitConfigLibrary::ReadConfigBool(const FString& ConfigFileName, const FString& Section, const FString& Key, bool& Value)
{
    return GConfig->GetBool(*Section, *Key, Value, GetConfigPath(ConfigFileName));
}

bool UCockpitConfigLibrary::ReadConfigInt(const FString& ConfigFileName, const FString& Section, const FString& Key, int32& Value)
{
    return GConfig->GetInt(*Section, *Key, Value, GetConfigPath(ConfigFileName));
}

bool UCockpitConfigLibrary::ReadConfigFloat(const FString& ConfigFileName, const FString& Section, const FString& Key, float& Value)
{
    return GConfig->GetFloat(*Section, *Key, Value, GetConfigPath(ConfigFileName));
}

bool UCockpitConfigLibrary::ReadConfigString(const FString& ConfigFileName, const FString& Section, const FString& Key, FString& Value)
{
    return GConfig->GetString(*Section, *Key, Value, GetConfigPath(ConfigFileName));
}

bool UCockpitConfigLibrary::ReadConfigVector(const FString& ConfigFileName, const FString& Section, const FString& Key, FVector& Value)
{
    FString VectorStr;
    if (GConfig->GetString(*Section, *Key, VectorStr, GetConfigPath(ConfigFileName)))
    {
        return Value.InitFromCompactString(VectorStr);
    }
    return false;
}

//bool UCockpitConfigLibrary::ReadRotator(const FString& Section, const FString& Key, FRotator& Value)
bool UCockpitConfigLibrary::ReadConfigRotator(const FString& ConfigFileName, const FString& Section, const FString& Key, FRotator& Value)
{
    FString RotatorStr;
    if (!ReadConfigString(ConfigFileName, Section, Key, RotatorStr)) return false;

    return Value.InitFromString(RotatorStr);
}

bool UCockpitConfigLibrary::WriteConfig(const FString& ConfigFileName, const FString& Section, const FString& Key, const FString& Value)
{
    FString ConfigPath = GetConfigPath(ConfigFileName);

    // 先设置到 GConfig 缓存
    GConfig->SetString(*Section, *Key, *Value, ConfigPath);

    // 立即刷写到磁盘（Saved/Config 目录下）
    GConfig->Flush(false, ConfigPath);    

    return true;
}

bool UCockpitConfigLibrary::WriteConfigBool(const FString& ConfigFileName, const FString& Section, const FString& Key, bool Value)
{
    return WriteConfig(ConfigFileName, Section, Key, Value ? TEXT("true") : TEXT("false"));
}

bool UCockpitConfigLibrary::WriteConfigInt(const FString& ConfigFileName, const FString& Section, const FString& Key, int32 Value)
{
    return WriteConfig(ConfigFileName, Section, Key, FString::FromInt(Value));
}

bool UCockpitConfigLibrary::WriteConfigFloat(const FString& ConfigFileName, const FString& Section, const FString& Key, float Value)
{
    return WriteConfig(ConfigFileName, Section, Key, FString::SanitizeFloat(Value));
}

bool UCockpitConfigLibrary::WriteConfigVector(const FString& ConfigFileName, const FString& Section, const FString& Key, const FVector& Value)
{
    FString ValueStr = FString::Printf(TEXT("X=%f Y=%f Z=%f"), Value.X, Value.Y, Value.Z);
    return WriteConfig(ConfigFileName, Section, Key, ValueStr);
}

bool UCockpitConfigLibrary::WriteConfigRotator(const FString& ConfigFileName, const FString& Section, const FString& Key, const FRotator& Value)
{
    FString ValueStr = FString::Printf(TEXT("P=%f Y=%f R=%f"), Value.Pitch, Value.Yaw, Value.Roll);
    return WriteConfig(ConfigFileName, Section, Key, ValueStr);
}

bool UCockpitConfigLibrary::IsConfigFileExists(const FString& ConfigFileName)
{
    return FPaths::FileExists(GetConfigPath(ConfigFileName));
}

void UCockpitConfigLibrary::ReloadConfig(const FString& ConfigFileName)
{
    const FString FilePath = GetConfigPath(ConfigFileName);
    if (FPaths::FileExists(FilePath))
    {
        // 卸载旧文件，重新加载
        GConfig->UnloadFile(FilePath);
        GConfig->LoadFile(FilePath);
        UE_LOG(LogTemp, Log, TEXT("CockpitConfig reloaded from: %s"), *FilePath);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("CockpitConfig not found: %s"), *FilePath);
    }
}