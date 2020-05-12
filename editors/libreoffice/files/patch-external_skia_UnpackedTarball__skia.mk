--- external/skia/UnpackedTarball_skia.mk.orig	2020-05-06 18:00:34 UTC
+++ external/skia/UnpackedTarball_skia.mk
@@ -34,6 +34,7 @@ skia_patches := \
     fix-without-gl.patch.0 \
     extend-rgb-to-rgba.patch.0 \
     windows-typeface-directwrite.patch.0 \
+    vk_mem_alloc.h.patch.0
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
