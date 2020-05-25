--- glib/gmacros.h.orig	2020-05-20 10:46:43 UTC
+++ glib/gmacros.h
@@ -532,7 +532,7 @@
 /**
  * G_GNUC_FALLTHROUGH:
  *
- * Expands to the GNU C `fallthrough` statement attribute if the compiler is gcc.
+ * Expands to the GNU C `fallthrough` statement attribute if the compiler supports it.
  * This allows declaring case statement to explicitly fall through in switch
  * statements. To enable this feature, use `-Wimplicit-fallthrough` during
  * compilation.
@@ -558,6 +558,8 @@
  * Since: 2.60
  */
 #if    __GNUC__ > 6
+#define G_GNUC_FALLTHROUGH __attribute__((fallthrough))
+#elif g_macro__has_attribute (fallthrough)
 #define G_GNUC_FALLTHROUGH __attribute__((fallthrough))
 #else
 #define G_GNUC_FALLTHROUGH
