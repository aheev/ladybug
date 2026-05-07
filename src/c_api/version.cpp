#include "main/version.h"

#include <string>

#include "c_api/helpers.h"
#include "c_api/lbug.h"
#include "storage/storage_version_info.h"

char* lbug_get_version() {
    return convertToOwnedCString(lbug::main::Version::getVersion());
}

uint64_t lbug_get_storage_version() {
    return lbug::main::Version::getStorageVersion();
}

char* lbug_get_storage_version_info_string() {
    auto info = lbug::storage::StorageVersionInfo::getStorageVersionInfo();
    std::string json = "{";
    bool first = true;
    for (auto& [version, storageVersion] : info) {
        if (!first) {
            json += ",";
        }
        json += "\"" + version + "\":" + std::to_string(storageVersion);
        first = false;
    }
    json += "}";
    return convertToOwnedCString(json);
}
