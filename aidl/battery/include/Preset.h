/*
 * Copyright (C) 2025 The Nameless-CLO Project
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include "Battery.h"

using ::aidl::vendor::nameless::hardware::battery::DeviceInfo;
using ::aidl::vendor::nameless::hardware::battery::Feature;
using ::aidl::vendor::nameless::hardware::battery::FeatureNode;
using ::aidl::vendor::nameless::hardware::battery::NodeInfo;

/** Preset node starts */
static const NodeInfo VOOC_CHARING_NODE = {
    .path = "/sys/class/oplus_chg/battery/voocchg_ing",
    .readDisabledPrefix = "0"
};

static const NodeInfo CHARGING_SUSPEND_NODE = {
    .path = "/sys/class/oplus_chg/battery/mmi_charging_enable",
    .readDisabledPrefix = "1",
    .writeEnableValue = "0",
    .writeDisableValue = "1"
};

static const NodeInfo WIRELESS_RX_NODE = {
    .path = "/proc/wireless/enable_rx",
    .readDisabledPrefix = "0",
    .writeEnableValue = "1",
    .writeDisableValue = "0"
};

static const NodeInfo WIRELESS_TX_NODE = {
    .path = "/proc/wireless/enable_tx",
    .readDisabledPrefix = "disable",
    .writeEnableValue = "1",
    .writeDisableValue = "0"
};

static const NodeInfo WIRELESS_QUIET_MODE_NODE = {
    .path = "/proc/wireless/quiet_mode",
    .readDisabledPrefix = "false",
    .writeEnableValue = "1",
    .writeDisableValue = "0"
};

static const NodeInfo WIRELESS_QUIET_MODE_NEW_NODE = {
    .path = "/proc/wireless/user_sleep_mode",
    .readDisabledPrefix = "0",
    .writeEnableValue = "1",
    .writeDisableValue = "0"
};
/** Preset node ends */

/** Preset device info starts */
static const DeviceInfo PRESET_EMPTY_FEATURE = {
    .supportedFeatures = 0,
    .featureNode = {
        .voocChgingNode = VOOC_CHARING_NODE
    }
};

static const DeviceInfo PRESET_SUSPEND_CHARGING_ONLY = {
    .supportedFeatures = static_cast<int>(Feature::SUSPEND_CHARGING),
    .featureNode = {
        .voocChgingNode = VOOC_CHARING_NODE,
        .chargingSuspendNode = CHARGING_SUSPEND_NODE
    }
};

static const DeviceInfo PRESET_ALL_FEATURE = {
    .supportedFeatures = static_cast<int>(Feature::SUSPEND_CHARGING) |
                         static_cast<int>(Feature::WIRELESS_CHARGING_RX) |
                         static_cast<int>(Feature::WIRELESS_CHARGING_TX) |
                         static_cast<int>(Feature::WIRELESS_CHARGING_QUIET_MODE),
    .featureNode = {
        .voocChgingNode = VOOC_CHARING_NODE,
        .chargingSuspendNode = CHARGING_SUSPEND_NODE,
        .wirelessRxNode = WIRELESS_RX_NODE,
        .wirelessTxNode = WIRELESS_TX_NODE,
        .wirelessQuietModeNode = WIRELESS_QUIET_MODE_NODE
    }
};

static const DeviceInfo PRESET_ALL_FEATURE_NEW_QUIET_MODE = {
    .supportedFeatures = static_cast<int>(Feature::SUSPEND_CHARGING) |
                         static_cast<int>(Feature::WIRELESS_CHARGING_RX) |
                         static_cast<int>(Feature::WIRELESS_CHARGING_TX) |
                         static_cast<int>(Feature::WIRELESS_CHARGING_QUIET_MODE),
    .featureNode = {
        .voocChgingNode = VOOC_CHARING_NODE,
        .chargingSuspendNode = CHARGING_SUSPEND_NODE,
        .wirelessRxNode = WIRELESS_RX_NODE,
        .wirelessTxNode = WIRELESS_TX_NODE,
        .wirelessQuietModeNode = WIRELESS_QUIET_MODE_NEW_NODE
    }
};
/** Preset device info ends */
