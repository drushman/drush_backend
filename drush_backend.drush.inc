<?php

/**
 * @file
 * LMS module drush integration.
 */

/**
 * Implements hook_drush_command().
 *
 * @return
 *   An associative array describing your command(s).
 *
 * @see drush_parse_command()
 */
function drush_backend_drush_command() {
  $items = array();
  $items['backend-links'] = array(
    'description' => "List menu links module on your site.",
    'arguments' => array(
      'module' => 'A space delimited list of module.',
    ),
    'options' => array(
      'list' => "List view'",
    ),
    'aliases' => array('bl'),
  );
  return $items;
}

/**
 * Update an existing feature module.
 */
function drush_drush_backend_backend_links() {
  $list_view = drush_get_option('list');
  if ($args = func_get_args()) {
    foreach ($args as $module) {
      if (function_exists("{$module}_menu")) {
        $items = call_user_func("{$module}_menu");
        $list_view ? print_r(array_keys($items)) : print_r($items);
      }
      
      $items = drush_backend_views_links($module);
      $list_view ? print_r(array_keys($items)) : print_r($items);
    }
  }
}
