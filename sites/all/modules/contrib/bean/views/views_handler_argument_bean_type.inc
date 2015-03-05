<?php
/**
 * Argument to accept bean type
 *
 */
class views_handler_argument_bean_type extends views_handler_argument_string {
  function title() {
    $title = db_query("SELECT title FROM {bean} v WHERE type = :type", array(':type' => $this->argument))->fetchField();

    if (empty($title)) {
      return t('No bean type');
    }
    return check_plain($title);
  }
}
