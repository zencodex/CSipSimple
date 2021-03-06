/*
 *  Copyright (c) 2012 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef WEBRTC_VIDEO_ENGINE_VIE_BASE_IMPL_H_
#define WEBRTC_VIDEO_ENGINE_VIE_BASE_IMPL_H_

#include "video_engine/include/vie_base.h"
#include "video_engine/vie_defines.h"
#include "video_engine/vie_ref_count.h"
#include "video_engine/vie_shared_data.h"

namespace webrtc {

class Module;
class VoiceEngine;

class ViEBaseImpl
    : public ViEBase,
      public ViERefCount {
 public:
  virtual int Release();

  // Implements ViEBase.
  virtual int Init();
  virtual int SetVoiceEngine(VoiceEngine* voice_engine);
  virtual int CreateChannel(int& video_channel);  // NOLINT
  virtual int CreateChannel(int& video_channel,  // NOLINT
                            int original_channel);
  virtual int CreateReceiveChannel(int& video_channel,  // NOLINT
                                   int original_channel);
  virtual int DeleteChannel(const int video_channel);
  virtual int ConnectAudioChannel(const int video_channel,
                                  const int audio_channel);
  virtual int DisconnectAudioChannel(const int video_channel);
  virtual int StartSend(const int video_channel);
  virtual int StopSend(const int video_channel);
  virtual int StartReceive(const int video_channel);
  virtual int StopReceive(const int video_channel);
  virtual int RegisterObserver(ViEBaseObserver& observer);  // NOLINT
  virtual int DeregisterObserver();
  virtual int GetVersion(char version[1024]);
  virtual int LastError();

 protected:
  ViEBaseImpl();
  virtual ~ViEBaseImpl();

  ViESharedData* shared_data() { return &shared_data_; }

 private:
  // Version functions.
  WebRtc_Word32 AddViEVersion(char* str) const;
  WebRtc_Word32 AddBuildInfo(char* str) const;
  WebRtc_Word32 AddExternalTransportBuild(char* str) const;

  int CreateChannel(int& video_channel, int original_channel,  // NOLINT
                    bool sender);

  // ViEBaseImpl owns ViESharedData used by all interface implementations.
  ViESharedData shared_data_;
};

}  // namespace webrtc

#endif  // WEBRTC_VIDEO_ENGINE_VIE_BASE_IMPL_H_
