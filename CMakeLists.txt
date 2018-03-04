CMAKE_MINIMUM_REQUIRED( VERSION 3.9 )
PROJECT( qwt )

OPTION( QWT_PLOT "Enable QwtPlot" ON )
OPTION( QWT_WIDGETS "Enable QwtWidgets" ON )
OPTION( QWT_EXAMPLES "Enable QwtExamples" ON )

SET( CMAKE_CXX_STANDARD 11 )
SET( CMAKE_INCLUDE_CURRENT_DIR ON )
SET( CMAKE_AUTOMOC ON )
SET( CMAKE_AUTORCC ON )

FIND_PACKAGE( Qt5 COMPONENTS 
  Widgets Svg PrintSupport Concurrent OpenGL REQUIRED )

SET( QWT_SRC
  src/qwt_abstract_scale_draw.cpp
  src/qwt_clipper.cpp
  src/qwt_color_map.cpp
  src/qwt_column_symbol.cpp
  src/qwt_date.cpp
  src/qwt_date_scale_draw.cpp
  src/qwt_date_scale_engine.cpp
  src/qwt_dyngrid_layout.cpp
  src/qwt_event_pattern.cpp
  src/qwt_graphic.cpp
  src/qwt_interval.cpp
  src/qwt_interval_symbol.cpp
  src/qwt_math.cpp
  src/qwt_magnifier.cpp
  src/qwt_null_paintdevice.cpp
  src/qwt_painter.cpp
  src/qwt_painter_command.cpp
  src/qwt_panner.cpp
  src/qwt_picker.cpp
  src/qwt_picker_machine.cpp
  src/qwt_pixel_matrix.cpp
  src/qwt_point_3d.cpp
  src/qwt_point_polar.cpp
  src/qwt_round_scale_draw.cpp
  src/qwt_scale_div.cpp
  src/qwt_scale_draw.cpp
  src/qwt_scale_map.cpp
  src/qwt_spline.cpp
  src/qwt_scale_engine.cpp
  src/qwt_symbol.cpp
  src/qwt_system_clock.cpp
  src/qwt_text_engine.cpp
  src/qwt_text_label.cpp
  src/qwt_text.cpp
  src/qwt_transform.cpp
  src/qwt_widget_overlay.cpp
)

IF( QWT_PLOT )
  LIST( APPEND QWT_SRC
    src/qwt_curve_fitter.cpp
    src/qwt_abstract_legend.cpp
    src/qwt_legend.cpp
    src/qwt_legend_data.cpp
    src/qwt_legend_label.cpp
    src/qwt_plot.cpp
    src/qwt_plot_renderer.cpp
    src/qwt_plot_xml.cpp
    src/qwt_plot_axis.cpp
    src/qwt_plot_curve.cpp
    src/qwt_plot_dict.cpp
    src/qwt_plot_directpainter.cpp
    src/qwt_plot_grid.cpp
    src/qwt_plot_histogram.cpp
    src/qwt_plot_item.cpp
    src/qwt_plot_abstract_barchart.cpp
    src/qwt_plot_barchart.cpp
    src/qwt_plot_multi_barchart.cpp
    src/qwt_plot_intervalcurve.cpp
    src/qwt_plot_zoneitem.cpp
    src/qwt_plot_tradingcurve.cpp
    src/qwt_plot_spectrogram.cpp
    src/qwt_plot_spectrocurve.cpp
    src/qwt_plot_scaleitem.cpp
    src/qwt_plot_legenditem.cpp
    src/qwt_plot_seriesitem.cpp
    src/qwt_plot_shapeitem.cpp
    src/qwt_plot_marker.cpp
    src/qwt_plot_textlabel.cpp
    src/qwt_plot_layout.cpp
    src/qwt_plot_canvas.cpp
    src/qwt_plot_panner.cpp
    src/qwt_plot_rasteritem.cpp
    src/qwt_plot_picker.cpp
    src/qwt_plot_zoomer.cpp
    src/qwt_plot_magnifier.cpp
    src/qwt_plot_rescaler.cpp
    src/qwt_point_mapper.cpp
    src/qwt_raster_data.cpp
    src/qwt_matrix_raster_data.cpp
    src/qwt_sampling_thread.cpp
    src/qwt_series_data.cpp
    src/qwt_point_data.cpp
    src/qwt_scale_widget.cpp 
  )
ENDIF()

LIST( APPEND QWT_SRC src/qwt_plot_svgitem.cpp )
LIST( APPEND QWT_SRC src/qwt_plot_glcanvas.cpp )

IF( QWT_WIDGETS )
  LIST( APPEND QWT_SRC
    src/qwt_abstract_slider.cpp
    src/qwt_abstract_scale.cpp
    src/qwt_arrow_button.cpp
    src/qwt_analog_clock.cpp
    src/qwt_compass.cpp
    src/qwt_compass_rose.cpp
    src/qwt_counter.cpp
    src/qwt_dial.cpp
    src/qwt_dial_needle.cpp
    src/qwt_knob.cpp
    src/qwt_slider.cpp
    src/qwt_thermo.cpp
    src/qwt_wheel.cpp
  )
ENDIF()

ADD_LIBRARY( qwt ${QWT_SRC} )
TARGET_LINK_LIBRARIES( qwt PUBLIC 
  Qt5::Widgets
  Qt5::Svg
  Qt5::PrintSupport 
  Qt5::Concurrent
  Qt5::OpenGL
)
TARGET_INCLUDE_DIRECTORIES( qwt INTERFACE src )

IF( QWT_EXAMPLES )
  ADD_EXECUTABLE( refreshtest
    examples/refreshtest/circularbuffer.cpp
    examples/refreshtest/panel.cpp
    examples/refreshtest/plot.cpp
    examples/refreshtest/mainwindow.cpp
    examples/refreshtest/main.cpp
  )
  TARGET_LINK_LIBRARIES( refreshtest qwt )
ENDIF()
