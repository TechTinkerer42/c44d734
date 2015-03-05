<?php
/**
 * @file
 * core00_core.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function core00_core_default_rules_configuration() {
  $items = array();
  $items['rules_login_redirect'] = entity_import('rules_config', '{ "rules_login_redirect" : {
      "LABEL" : "Login Redirect",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "redirection" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_login" : [] },
      "DO" : [ { "redirect" : { "url" : "[site:url]" } } ]
    }
  }');
  return $items;
}
