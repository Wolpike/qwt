CMAKE_MINIMUM_REQUIRED( VERSION 3.9 )
PROJECT( qwt )

OPTION( QWT_PLOT "Enable QwtPlot" ON )
OPTION( QWT_WIDGETS "Enable QwtWidgets" ON )
OPTION( QWT_EXAMPLES "Enable QwtExamples" OFF )
OPTION( QWT_PLAYGROUND "Enable QwtPlayground" OFF )

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
  src/qwt_bezier.cpp
  src/qwt_spline_basis.cpp
  src/qwt_spline_cubic.cpp
  src/qwt_spline_curve_fitter.cpp
  src/qwt_spline_local.cpp
  src/qwt_spline_parametrization.cpp
  src/qwt_spline_pleasing.cpp
  src/qwt_weeding_curve_fitter.cpp
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
  IF( QWT_PLOT )
    ADD_EXECUTABLE( animation
      examples/animation/plot.cpp
      examples/animation/main.cpp
    )
    TARGET_LINK_LIBRARIES( animation qwt )

    ADD_EXECUTABLE( barchart
      examples/barchart/barchart.cpp
      examples/barchart/main.cpp
    )
    TARGET_LINK_LIBRARIES( barchart qwt )

    ADD_EXECUTABLE( cpuplot
      examples/cpuplot/cpuplot.cpp
      examples/cpuplot/cpupiemarker.cpp
      examples/cpuplot/cpustat.cpp
    )
    TARGET_LINK_LIBRARIES( cpuplot qwt )

    ADD_EXECUTABLE( curvdemo1
      examples/curvdemo1/curvdemo1.cpp
    )
    TARGET_LINK_LIBRARIES( curvdemo1 qwt )

    ADD_EXECUTABLE( distrowatch
      examples/distrowatch/main.cpp
      examples/distrowatch/barchart.cpp
    )
    TARGET_LINK_LIBRARIES( distrowatch qwt )

    ADD_EXECUTABLE( friedberg
      examples/friedberg/main.cpp
      examples/friedberg/plot.cpp
      examples/friedberg/friedberg2007.cpp
    )
    TARGET_LINK_LIBRARIES( friedberg qwt )

    ADD_EXECUTABLE( itemeditor
      examples/itemeditor/main.cpp
      examples/itemeditor/plot.cpp
      examples/itemeditor/editor.cpp
      examples/itemeditor/shapefactory.cpp
    )
    TARGET_LINK_LIBRARIES( itemeditor qwt )

    ADD_EXECUTABLE( legends
      examples/legends/main.cpp
      examples/legends/mainwindow.cpp
      examples/legends/plot.cpp
      examples/legends/panel.cpp
    )
    TARGET_LINK_LIBRARIES( legends qwt )

    ADD_EXECUTABLE( rasterview
      examples/rasterview/main.cpp
      examples/rasterview/plot.cpp
    )
    TARGET_LINK_LIBRARIES( rasterview qwt )

    ADD_EXECUTABLE( realtime
      examples/realtime/main.cpp
      examples/realtime/mainwindow.cpp
      examples/realtime/incrementalplot.cpp
      examples/realtime/randomplot.cpp
      examples/realtime/scrollbar.cpp
      examples/realtime/scrollzoomer.cpp
    )
    TARGET_LINK_LIBRARIES( realtime qwt )

    ADD_EXECUTABLE( refreshtest
      examples/refreshtest/circularbuffer.cpp
      examples/refreshtest/panel.cpp
      examples/refreshtest/plot.cpp
      examples/refreshtest/mainwindow.cpp
      examples/refreshtest/main.cpp
    )
    TARGET_LINK_LIBRARIES( refreshtest qwt )

    ADD_EXECUTABLE( scatterplot
      examples/scatterplot/main.cpp
      examples/scatterplot/mainwindow.cpp
      examples/scatterplot/plot.cpp
    )
    TARGET_LINK_LIBRARIES( scatterplot qwt )

    ADD_EXECUTABLE( simpleplot
      examples/simpleplot/simpleplot.cpp
    )
    TARGET_LINK_LIBRARIES( simpleplot qwt )

    ADD_EXECUTABLE( sinusplot
      examples/sinusplot/sinusplot.cpp
    )
    TARGET_LINK_LIBRARIES( sinusplot qwt )

    ADD_EXECUTABLE( spectrogram
      examples/spectrogram/main.cpp
      examples/spectrogram/plot.cpp
    )
    TARGET_LINK_LIBRARIES( spectrogram qwt )

    ADD_EXECUTABLE( stockchart
      examples/stockchart/main.cpp
      examples/stockchart/plot.cpp
      examples/stockchart/griditem.cpp
      examples/stockchart/legend.cpp
      examples/stockchart/quotefactory.cpp
    )
    TARGET_LINK_LIBRARIES( stockchart qwt )

    ADD_EXECUTABLE( tvplot
      examples/tvplot/main.cpp
      examples/tvplot/tvplot.cpp
    )
    TARGET_LINK_LIBRARIES( tvplot qwt )

    IF( QWT_WIDGETS )
      ADD_EXECUTABLE( event_filter
        examples/event_filter/canvaspicker.cpp
        examples/event_filter/colorbar.cpp
        examples/event_filter/event_filter.cpp
        examples/event_filter/plot.cpp
        examples/event_filter/scalepicker.cpp
      )
      TARGET_LINK_LIBRARIES( event_filter qwt )

      ADD_EXECUTABLE( bode
        examples/bode/main.cpp
        examples/bode/mainwindow.cpp
        examples/bode/plot.cpp
      )
      TARGET_LINK_LIBRARIES( bode qwt )

      ADD_EXECUTABLE( oscilloscope
        examples/oscilloscope/main.cpp
        examples/oscilloscope/curvedata.cpp
        examples/oscilloscope/knob.cpp
        examples/oscilloscope/mainwindow.cpp
        examples/oscilloscope/plot.cpp
        examples/oscilloscope/samplingthread.cpp
        examples/oscilloscope/signaldata.cpp
        examples/oscilloscope/wheelbox.cpp
      )
      TARGET_LINK_LIBRARIES( oscilloscope qwt )
    ENDIF()
  ENDIF()

  IF( QWT_WIDGETS )
    ADD_EXECUTABLE( radio
      examples/radio/mainwindow.cpp
      examples/radio/ampfrm.cpp
      examples/radio/radio.cpp
      examples/radio/tunerfrm.cpp
    )
    TARGET_LINK_LIBRARIES( radio qwt )

    ADD_EXECUTABLE( sysinfo
      examples/sysinfo/sysinfo.cpp
    )
    TARGET_LINK_LIBRARIES( sysinfo qwt )

    ADD_EXECUTABLE( dials
      examples/dials/dials.cpp
      examples/dials/attitude_indicator.cpp
      examples/dials/cockpit_grid.cpp
      examples/dials/compass_grid.cpp
      examples/dials/speedo_meter.cpp
    )
    TARGET_LINK_LIBRARIES( dials qwt )

    ADD_EXECUTABLE( controls
      examples/controls/sliderbox.cpp
      examples/controls/slidertab.cpp
      examples/controls/wheelbox.cpp
      examples/controls/wheeltab.cpp
      examples/controls/knobbox.cpp
      examples/controls/knobtab.cpp
      examples/controls/dialbox.cpp
      examples/controls/dialtab.cpp
      examples/controls/main.cpp
    )
    TARGET_LINK_LIBRARIES( controls qwt )
  ENDIF()
ENDIF()

IF( QWT_PLAYGROUND )
  IF( QWT_PLOT )
    ADD_EXECUTABLE( curvetracker
      playground/curvetracker/curvetracker.cpp
      playground/curvetracker/plot.cpp
      playground/curvetracker/main.cpp
    )
    TARGET_LINK_LIBRARIES( curvetracker qwt )

    ADD_EXECUTABLE( graphicscale
      playground/graphicscale/canvas.cpp
      playground/graphicscale/main.cpp
      playground/graphicscale/mainwindow.cpp
    )
    TARGET_LINK_LIBRARIES( graphicscale qwt )

    ADD_EXECUTABLE( plotmatrix
      playground/plotmatrix/plotmatrix.cpp
      playground/plotmatrix/main.cpp
    )
    TARGET_LINK_LIBRARIES( plotmatrix qwt )

    ADD_EXECUTABLE( rescaler
      playground/rescaler/plot.cpp
      playground/rescaler/main.cpp
      playground/rescaler/mainwindow.cpp
    )
    TARGET_LINK_LIBRARIES( rescaler qwt )

    ADD_EXECUTABLE( scaleengine
      playground/scaleengine/plot.cpp
      playground/scaleengine/mainwindow.cpp
      playground/scaleengine/scaleengine.cpp
      playground/scaleengine/transformplot.cpp
    )
    TARGET_LINK_LIBRARIES( scaleengine qwt )

    ADD_EXECUTABLE( shapes
      playground/shapes/shapes.cpp
    )
    TARGET_LINK_LIBRARIES( shapes qwt )

    ADD_EXECUTABLE( symbols
      playground/symbols/symbols.cpp
    )
    TARGET_LINK_LIBRARIES( symbols qwt )

    ADD_EXECUTABLE( timescale
      playground/timescale/plot.cpp
      playground/timescale/panel.cpp
      playground/timescale/main.cpp
      playground/timescale/mainwindow.cpp
    )
    TARGET_LINK_LIBRARIES( timescale qwt )

    ADD_EXECUTABLE( svgmap
      playground/svgmap/plot.cpp
      playground/svgmap/main.cpp
    )
    TARGET_LINK_LIBRARIES( svgmap qwt )
  ENDIF()
ENDIF()
