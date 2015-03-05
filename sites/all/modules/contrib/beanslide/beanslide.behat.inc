<?php
/**
 * @file
 * Provide Behat step-definitions as Drupal Extension subcontexts.
 */

use Drupal\DrupalExtension\Context\DrupalSubContextInterface;
use Behat\Behat\Context\BehatContext;

class BeanslideSubContext extends BehatContext implements DrupalSubContextInterface {
  public static function getAlias() {
    return 'beanslide';
  }

  /**
   * @Then /^I should be on slide "(?P<slide>\d+)"$/
   */
  public function assertCurrentSlide($slide) {
    $slideshow = $this->getMainContext()->getSession()->getPage()->find('css', '.beanslide');
    if (!$slideshow) {
      throw new \Exception(sprintf("No slideshow found on the page %s", $this->getSession()->getCurrentUrl()));
    }

    // Loop through slides until we're on number passed in `$slide`.
    $slides = $slideshow->findAll('css', 'ul.slides li');
    if (!$slides || (count($slides) < $slide)) {
      throw new \Exception(sprintf("There are not enough slides on page %s for slide number %s to be active.", $this->getMainContext()->getSession()->getCurrentUrl(), $slide));
    }

    foreach ($slides as $i => $current_slide) {
      if ($slide == ($i + 1)) {
        // This should be the active slide, so detect if it is visible.
        $style_attr = $current_slide->getAttribute('style');
        if (strpos($style_attr, 'display: none') !== FALSE) {
          throw new \Exception(sprintf("Slide number %s is hidden instead of active at %s", $slide, $this->getMainContext()->getSession()->getCurrentUrl()));
        }
        return;
      }
    }

    throw new \Exception(sprintf("No active slides found at %s", $this->getMainContext()->getSession()->getCurrentUrl()));
  }

  /**
   * @Then /^I should see a slideshow$/
   */
  public function assertSlideshowExists() {
    $slideshow = $this->getMainContext()->getSession()->getPage()->find('css', '.beanslide');
    if (!$slideshow) {
      throw new \Exception(sprintf("No slideshow found on the page %s", $this->getSession()->getCurrentUrl()));
    }
  }
}
