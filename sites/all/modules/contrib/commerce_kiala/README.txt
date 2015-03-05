Commerce Kiala is packaged for download at http://drupal.org/project/commerce_kiala.
Learn more at http://drupal.org/project/commerce_kiala

Installation
*** This module depends on Commerce Shipping 2.x. ***
[1] Place the entirety of this directory in your site's modules directory,
  ex. sites/all/modules/commerce_kiala

[2] Update the shipping method settings at
  admin/commerce/config/shipping/methods/kiala/edit.
  Common settings to change:
  - Common >> Merchant ID: change based on Kiala account
  - Kiala Point Search >> Embedding Type: enable a floaty box method.
     Currently supported: lightbox2, colorbox
  - Track and Trace >> Embedding Type: enable a floaty box method.

[3] Add a Kiala rate shipping service at
  admin/commerce/config/shipping/services/kiala.


Kiala Pack & Ship Integration
* Commerce Physical module is required.
http://www.drupal.org/project/commerce_physical
This module is used to define the physical properties (weight and dimensions)
of each product.


Test Account
* Test merchant ID (DSP ID): DEMO_DSP
* This account will not give you the right settings for use in a production
  environment!
* The shipping address during checkout must be in France to see the Kiala
  shipping option.
