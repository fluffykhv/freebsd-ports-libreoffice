--- pangox.c.orig	2012-08-27 23:19:32 UTC
+++ pangox.c
@@ -279,7 +279,8 @@ pango_x_font_class_init (PangoXFontClass *class)
 
   font_class->describe = pango_x_font_describe;
   font_class->get_coverage = pango_x_font_get_coverage;
-  font_class->find_shaper = pango_x_font_find_shaper;
+//  Disable deprecated
+//  font_class->find_shaper = pango_x_font_find_shaper;
   font_class->get_glyph_extents = pango_x_font_get_glyph_extents;
   font_class->get_metrics = pango_x_font_get_metrics;
   font_class->get_font_map = pango_x_font_get_font_map;
@@ -1344,21 +1345,6 @@ pango_x_font_describe (PangoFont *font)
     return NULL;
 }
 
-PangoMap *
-pango_x_get_shaper_map (PangoLanguage *language)
-{
-  static guint engine_type_id = 0;
-  static guint render_type_id = 0;
-
-  if (engine_type_id == 0)
-    {
-      engine_type_id = g_quark_from_static_string (PANGO_ENGINE_TYPE_SHAPE);
-      render_type_id = g_quark_from_static_string (PANGO_RENDER_TYPE_X);
-    }
-
-  return pango_find_map (language, engine_type_id, render_type_id);
-}
-
 static PangoCoverage *
 pango_x_font_get_coverage (PangoFont     *font,
 			   PangoLanguage *language)
@@ -1373,12 +1359,11 @@ pango_x_font_find_shaper (PangoFont     *font G_GNUC_U
 			  PangoLanguage *language,
 			  guint32        ch)
 {
-  PangoMap *shape_map = NULL;
-  PangoScript script;
-
-  shape_map = pango_x_get_shaper_map (language);
-  script = pango_script_for_unichar (ch);
-  return (PangoEngineShape *)pango_map_get_engine (shape_map, script);
+  static PangoEngineShape *shaper;
+  if (g_once_init_enter (&shaper))
+    g_once_init_leave (&shaper,
+		       _pango_basic_x_script_engine_create("BasicScriptEngineXCompat"));
+  return shaper;
 }
 
 /* Utility functions */
