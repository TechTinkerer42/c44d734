This module provides a Profile2 Feeds plugin to allow you to import Profile2 
profiles into your project. Draws on Field Collection Feeds and 
<a href="https://drupal.org/node/1228062">#1228062: How to import 
Profile2-fields with new Users</a> (specifically the 
patch on comment #58) for inspiration. It probably won't be necessary once one 
or more of the following things happen:

  * This issue gets resolved: <a href="https://drupal.org/node/1033202">
    #1033202: [Meta] Generic entity processor</a>
  * Profile2 includes the plugin as part of it's project.

Until then, this seems like a cleaner way of adding the functionality than 
patching the Feeds module (and then maintaining that patch).

Should work with:

  * Feeds 7.x-2.0-alpha8
  * Profile2 7.x-1.3
  * Feeds XPath Parser 7.x-1.0-beta4 (though will probably work fine with CSV 
    import)

Beyond that, no guarantees at this point.
