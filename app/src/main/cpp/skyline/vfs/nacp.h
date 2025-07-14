// SPDX-License-Identifier: MPL-2.0
// Copyright © 2020 Skyline Team and Contributors (https://github.com/skyline-emu/)

#pragma once

#include <common/language.h>
#include "backing.h"

namespace skyline::vfs {
    /**
     * @brief The NACP class provides easy access to the data found in an NACP file
     * @url https://switchbrew.org/wiki/NACP_Format
     */
    class NACP {
      private:
        /**
         * @brief The title data of an application for one language
         */
        struct ApplicationTitle {
            std::array<char, 0x200> applicationName; //!< The name of the application
            std::array<char, 0x100> applicationPublisher; //!< The publisher of the application
        };
        static_assert(sizeof(ApplicationTitle) == 0x300);

      public:
        struct NacpData {
            std::array<ApplicationTitle, 0x10> titleEntries; //!< Title entries for each language
            std::array<u8, 0x25> isbn;
            u8  startupUserAccount;
            u8  userAccountSwitchLock;
            u8  addonContentRegistrationType;
            u32 attributeFlag;
            u32 supportedLanguageFlag; //!< A bitmask containing the game's supported languages
            u32 parentalControlFlag;
            u8  screenshotEnabled;
            u8  videoCaptureMode;
            u8  dataLossConfirmation;
            u8  playLogPolicy;
            u64 presenceGroupId;
            std::array<u8, 0x20> ratingAge;
            std::array<char, 0x10> displayVersion; //!< The user-readable version of the application
            u64 addOnContentBaseId;
            u64 saveDataOwnerId; //!< The ID that should be used for this application's savedata
            u64 userAccountSaveDataSize;
            u64 userAccountSaveDataJournalSize;
            u64 deviceSaveDataSize;
            u64 deviceSaveDataJournalSize;
            u64 bcatDeliveryCacheStorageSize;
            char applicationErrorCodeCategory[8];
            std::array<u64, 8> localCommunicationId;
            u8  logoType;
            u8  logoHandling;
            u8  runtimeAddOnContentInstall;
            u8  runtimeParameterDelivery;
            u8  appropriateAgeForChina;
            u8  _pad0_[1];
            u8  crashReport;
            u8  hdcp;
            u64 seedForPseudoDeviceId; //!< Seed that is combined with the device seed for generating the pseudo-device ID
            std::array<u8, 0x41> bcatPassphrase;
            u8  startupUserAccountOption;
            std::array<u8, 0x6> reservedForUserAccountSaveDataOperation;
            u64 userAccountSaveDataSizeMax;
            u64 userAccountSaveDataJournalSizeMax;
            u64 deviceSaveDataSizeMax;
            u64 deviceSaveDataJournalSizeMax;
            u64 temporaryStorageSize;
            u64 cacheStorageSize;
            u64 cacheStorageJournalSize;
            u64 cacheStorageDataAndJournalSize;
            u16 cacheStorageIndexMax;
            u8  _pad1_[1];
            u8  runtimeUpgrade;
            u32 supportingLimitedApplicationLicenses;
            std::array<u64, 16> playLogQueryableApplicationId;
            u8  playLogQueryCapability;
            u8  repairFlag;
            u8  programIndex;
            u8  requiredNetworkServiceLicenseOnLaunchFlag;
            u8  applicationErrorCodePrefix; // 20.0.0+
            u8  _pad2_[1];
            u8  acdIndex; // 20.0.0+
            u8  apparentPlatform; // 20.0.0+
            std::array<u8, 0x198> neighborDetectionClientConfiguration;
            std::array<u8, 0x10> jitConfiguration;
            std::array<u8, 0x40> requiredAddOnContentsSetBinaryDescriptor;
            u8  playReportPermission;
            u8  crashScreenshotForProd;
            u8  crashScreenshotForDev;
            u8  contentsAvailabilityTransitionPolicy;
            u8  _pad3_[4];
            std::array<u8, 0x40> accessibleLaunchRequiredVersion;
            std::array<u8, 0x89> applicationControlDataCondition; // 20.0.0+
            u8  initialProgramIndex;
            u8  _pad4_[2];
            u32 accessibleProgramIndexFlags; // 20.0.0+
            u8  albumFileExport; // 20.0.0+
            u8  _pad5_[7];
            std::array<u8, 0x80> saveDataCertificateBytes; // 20.0.0+
            u8  hasInGameVoiceChat; // 20.0.0+
            u8  _pad6_[3];
            u32 supportedExtraAddOnContentFlag; // 20.0.0+
            u8  _pad7_[0x698];
            std::array<u8, 0x400> platformSpecificRegion; // 20.0.0+
        } nacpContents{};
        static_assert(sizeof(NacpData) == 0x4000);

        u32 supportedTitleLanguages{}; //!< A bitmask containing the available title entry languages and game icons

        NACP(const std::shared_ptr<vfs::Backing> &backing);

        language::ApplicationLanguage GetFirstSupportedTitleLanguage();

        language::ApplicationLanguage GetFirstSupportedLanguage();

        std::string GetApplicationName(language::ApplicationLanguage language);

        std::string GetApplicationVersion();

        std::string GetAddOnContentBaseId();

        std::string GetSaveDataOwnerId();

        std::string GetApplicationPublisher(language::ApplicationLanguage language);
    };
}
