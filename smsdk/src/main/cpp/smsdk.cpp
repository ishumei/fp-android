#include <jni.h>
#include <string>
#include <vector>
#include <unistd.h>
#include <fstream>

bool HasSu() {
  std::vector<std::string> SU_FILES = {
      "/system/bin/su",
      "/system/xbin/su",
      "/sbin/su",
      "/dev/magisk/mirror", "/magisk", "/sbin/.core/img/.core/hidelist",
      "/sbin/bank_spa", "/sbin/bank0301", "/sbin/bankfree", "/sbin/daemonsu", "/sbin/freebank",
      "/sbin/freeroot", "/sbin/spapa_su", "/sbin_orig", "/system/.bash/.ssu",
      "/system/app/SuperUser.apk", "/system/bin/.222/.su", "/system/bin/.ext/.su",
      "/system/bin/.good-job/.su", "/system/bin/.spapa/.su", "/system/xbin/sugote",
      "/data/data/bin/su", "/data/data/in/su", "/data/data/n/bstk/su", "/data/data/xbin/su",
      "/res/su", "/data/local/bin/su", "/data/local/su", "/data/local/xbin/su", "/system/su",
      "/data/su", "/magisk/.core/bin/su", "/su/bin/su", "/su/bin/sush",
      "/system/bin/failsafe/su", "/system/sbin/su", "/system/sd/xbin/su",
      "/system/xbin/noxsu", "/vendor/bin/su"
  };
  for (auto &iter: SU_FILES) {
    if (0 == access(iter.c_str(), F_OK)) {
      return true;
    }
  }
  return false;
}

std::vector<std::string> TxtFileContent(const std::string &filename) {
  std::vector<std::string> result;
  std::ifstream is(filename);
  if (!is.is_open()) {
    return std::move(result);
  }
  std::string s;
  while (getline(is, s)) {
    result.push_back(s);
  }
  return std::move(result);
}

jboolean ma() {
  std::vector<std::string> mounts = TxtFileContent("/proc/self/mounts");
  for (const auto &it: mounts) {
    if (it.find(".magisk") != std::string::npos) {
      return true;
    }
  }
  return false;
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_ishumei_smantifraud_SmAntiFraud_isRoot(
    JNIEnv *env,
    jobject /* this */) {
  return HasSu();
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_ishumei_smantifraud_SmAntiFraud_isHook(JNIEnv *env, jobject thiz) {
  return ma();
}