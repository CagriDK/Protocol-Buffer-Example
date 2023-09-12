# ProtoBuf Kurulumu

### Bilgilendirme 

#### **Bazel Build**

Basel LTS version bazel-6.3.2-windows-x86_64 indirilir.
-
[Bazel Release](https://github.com/bazelbuild/bazel/releases).
-
Basel_6.3.2 klasörü oluşturulur.
İçerisine bazel.exe atılır. (.exe adının bazel.exe olması gerekmektedir. Version bilgisi olmamalıdır.)
Edit environment içerisine path'e ...\bazel.exe eklenir.

#### Abseil ve Protobuf Kurulumu

Abseil LTS 20230125.3 indirilir.
Protocol Buffers v23.4 indirilir.
CMake indirilir.
-
[Abseil-cpp Release](https://github.com/abseil/abseil-cpp/releases).
[Protobuf Release](https://github.com/protocolbuffers/protobuf/releases).
[CMake Release](https://cmake.org/download/)
-
C Klasöründe "google" adlı bir klasör oluşturulur(Optional).
Abseil-cpp20230125.3 ve protobuf-23.4 kendi klasörlerine çıkartılır.

## **Abseil Build**
Abseil kurulumuna başlamak için cmake-gui açılır.
Compiler olarak mingw seçilir. Abseil içerisinde bir build dosyası oluşturulur ve src ve build dosyaları seçilir.
Configure edildikten sonra ABSL_PROPAGATE_CXX_STD aktif edilir.
CMake BUILD Test(Type?) deaktif edilir.
Install Path kullanıcı haklarına göre ayarlanır. (C:\google\absl)
Generate edilir.
Build dosyası klasörde açılır ve cmd girilir.
* cmake --build . -j12 
* cmake --install .
Kurulum sonrası C:/google/absl içerisine kurulum yapılmış olmaktadır.
Edit environment bölümünde ABSL_DIR = C\google\abls eklenir.

## **Protobuf Build**
Protobuf kurulumuna başlamak için cmake-gui açılır.
Compiler olarak mingw seçilir. Protobuf içerisinde bir build dosyası oluşturulur ve src ve build dosyaları seçilir.
Configure edildikten sonra Install Path kullanıcı haklarına göre ayarlanır. (C:\google\protobuf)
Protobuf_ABSL_PROVIDER module->package olarak degistirilir.
Protobuf_WITH_ZLIB deaktif edilir.
Protobuf_BUILD_TESTS deaktif edilir.
Protobuf_BUILD_EXAMPLES ve Protobuf_INSTALL_EXAMPLES aktif edilir.
Tekrar configure edilir. Gelen hatalar düzeltilir. (absl_DIR = C:/google/absl/lib/cmake/absl)
Generate edilir.
Build dosyası klasörde açılır ve cmd girilir.
* cmake --build . -j12 
* cmake --install .
Kurulum sonrası C:/google/protobuf içerisine kurulum yapılmış olmaktadır.

## Ortam değişkenlerinin ayarlanması

# Değişken olarak tanımlanacaklar
*   Protobuf_INCLUDE_DIR =  ...\google\protobuf\include
*   Protobuf_LIBRARIES   = 	...\google\protobuf\lib
*   Protobuf_ROOT 		 = 	...\google\protobuf 
*   ABSL_DIR             = 	...\google\abls (Optional)

# Path'e eklenecekler
*	...\mingw64\bin
*	...\cmake-3.24.3-windows-x86_64\bin
*	...\Basel_6.3.2
*	...\google\absl\lib
*	...\google\protobuf\bin
