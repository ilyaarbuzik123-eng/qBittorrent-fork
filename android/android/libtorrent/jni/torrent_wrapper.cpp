#include <jni.h>
#include <libtorrent/session.hpp>
#include <libtorrent/torrent_info.hpp>
#include <libtorrent/add_torrent_params.hpp>

using namespace lt;

extern "C" {

JNIEXPORT jlong JNICALL
Java_com_yourname_qbittorrent_LibTorrentWrapper_createSession(
    JNIEnv* env, jobject thiz) {
    settings_pack pack;
    // Настройки для Android
    pack.set_int(settings_pack::alert_mask, alert::error_notification | alert::status_notification);
    session* sess = new session(pack);
    return reinterpret_cast<jlong>(sess);
}

JNIEXPORT void JNICALL
Java_com_yourname_qbittorrent_LibTorrentWrapper_addTorrent(
    JNIEnv* env, jobject thiz, jlong sessionPtr, jstring magnet) {
    session* sess = reinterpret_cast<session*>(sessionPtr);
    const char* magnet_str = env->GetStringUTFChars(magnet, nullptr);
    
    add_torrent_params params;
    params.url = magnet_str;
    params.save_path = "/sdcard/Download/";
    
    sess->add_torrent(params);
    env->ReleaseStringUTFChars(magnet, magnet_str);
}

} // extern "C"
