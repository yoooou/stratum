#
# Copyright 2018 Google LLC
# Copyright 2018-present Open Networking Foundation
# Copyright 2019 Broadcom. All rights reserved. The term "Broadcom" refers to Broadcom Inc. and/or its subsidiaries.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

load("@bazel_tools//tools/build_defs/pkg:pkg.bzl", "pkg_tar", "pkg_deb")

licenses(["notice"])  # Apache v2

exports_files(["LICENSE"])

load(
    "//bazel:rules.bzl",
    "STRATUM_INTERNAL",
    "stratum_cc_binary",
    "stratum_package",
    "EMBEDDED_ARCHES",
)

package(
    #default_hdrs_check = "strict",
    default_visibility = STRATUM_INTERNAL,
)

licenses(["notice"])  # Apache v2

stratum_cc_binary(
    name = "stratum_bcm",
    srcs = [
        "main.cc",
    ],
    arches = EMBEDDED_ARCHES,
    linkopts = [
        "-lpthread",
        "-ldl",
        "-lutil",
        "-lrt",
        "-lyaml",
    ],
    deps = [
        "@com_github_google_glog//:glog",
        "//stratum/glue:init_google",
        "//stratum/glue:logging",
        "//stratum/hal/lib/bcm:bcm_acl_manager",
        "//stratum/hal/lib/bcm:bcm_chassis_manager",
        "//stratum/hal/lib/bcm:bcm_diag_shell",
        "//stratum/hal/lib/bcm:bcm_l2_manager",
        "//stratum/hal/lib/bcm:bcm_l3_manager",
        "//stratum/hal/lib/bcm:bcm_node",
        "//stratum/hal/lib/bcm:bcm_packetio_manager",
        "//stratum/hal/lib/bcm:bcm_sdk_wrapper",
        "//stratum/hal/lib/bcm:bcm_serdes_db_manager",
        "//stratum/hal/lib/bcm:bcm_switch",
        "//stratum/hal/lib/bcm:bcm_table_manager",
        "//stratum/hal/lib/bcm:bcm_tunnel_manager",
        "@com_github_opennetworkinglab_sdklt//:bcm_sdklt",
        "//stratum/hal/lib/common:hal",
        "//stratum/hal/lib/p4:p4_table_mapper",
        # TODO(craigs): need to add real phal deps here
        # "//stratum/hal/lib/phal:legacy_phal",
        # "//stratum/hal/lib/phal:udev",
        # "//stratum/hal/lib/phal:phal_sim",
        "//stratum/hal/lib/phal:phal",
        "//stratum/lib/security:auth_policy_checker",
        "//stratum/lib/security:credentials_manager",
        "@com_google_absl//absl/memory",
        "@com_google_absl//absl/synchronization",
    ],
)

stratum_package(
    name = "stratum_pkg",
    bins = [
        ":stratum_hal",
    ],
)

pkg_tar(
    name = "stratum_bcm_package",
    extension = "tar.gz",
    srcs = [
        ":stratum_bcm",
        "@com_github_opennetworkinglab_sdklt//:kernel_modules",
        "@com_github_opennetworkinglab_sdklt//:sdklt_cli",
    ],
    deps = [
        "//stratum/hal/config:configs",
    ],
    mode = "0755",
)
