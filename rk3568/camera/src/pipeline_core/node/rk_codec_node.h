/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *     http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef HOS_CAMERA_RKCODEC_NODE_H
#define HOS_CAMERA_RKCODEC_NODE_H

#include <vector>
#include <condition_variable>
#include <ctime>
#include <jpeglib.h>
#include "device_manager_adapter.h"
#include "utils.h"
#include "camera.h"
#include "source_node.h"
#include "RockchipRga.h"
#include "RgaUtils.h"
#include "RgaApi.h"
#include "rk_mpi.h"
#include "mpp_env.h"
#include "mpp_mem.h"
#include "mpp_log.h"
#include "mpp_common.h"
extern "C" {
#include "mpi_enc_utils.h"
}


namespace OHOS::Camera {
class RKCodecNode : public NodeBase {
public:
    RKCodecNode(const std::string& name, const std::string& type);
    ~RKCodecNode() override;
    RetCode Start(const int32_t streamId) override;
    RetCode Stop(const int32_t streamId) override;
    void DeliverBuffer(std::shared_ptr<IBuffer>& buffer) override;
    virtual RetCode Capture(const int32_t streamId, const int32_t captureId) override;
    RetCode CancelCapture(const int32_t streamId) override;
    RetCode Flush(const int32_t streamId);
private:
    void encodeJpegToMemory(unsigned char* image, int width, int height,
            const char* comment, size_t* jpegSize, unsigned char** jpegBuf);
    int findStartCode(unsigned char *data, size_t dataSz);
    void SerchIFps(unsigned char* buf, size_t bufSize, std::shared_ptr<IBuffer>& buffer);
    void Yuv420ToRGBA8888(std::shared_ptr<IBuffer>& buffer);
    void Yuv420ToJpeg(std::shared_ptr<IBuffer>& buffer);
    void Yuv420ToH264(std::shared_ptr<IBuffer>& buffer);

    static uint32_t                       previewWidth_;
    static uint32_t                       previewHeight_;
    std::vector<std::shared_ptr<IPort>>   outPutPorts_;
    void* halCtx_ = nullptr;
    int mppStatus_ = 0;
};
}// namespace OHOS::Camera
#endif
