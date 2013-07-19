<?php
/**
 * @file
 * basic_slider.features.inc
 */

/**
 * Implements hook_views_api().
 */
function basic_slider_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function basic_slider_image_default_styles() {
  $styles = array();

  // Exported image style: home_slider.
  $styles['home_slider'] = array(
    'name' => 'home_slider',
    'effects' => array(
      7 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 2200,
          'height' => 800,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function basic_slider_node_info() {
  $items = array(
    'slider_image' => array(
      'name' => t('Slider Image'),
      'base' => 'node_content',
      'description' => t('Use <em>slider images</em> to add images to your front page slideshow.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
