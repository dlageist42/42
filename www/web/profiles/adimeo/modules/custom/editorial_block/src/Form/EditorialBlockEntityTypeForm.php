<?php

namespace Drupal\editorial_block\Form;

use Drupal\Core\Entity\EntityForm;
use Drupal\Core\Form\FormStateInterface;

/**
 * Class EditorialBlockEntityTypeForm.
 */
class EditorialBlockEntityTypeForm extends EntityForm {

  /**
   * {@inheritdoc}
   */
  public function form(array $form, FormStateInterface $form_state) {
    $form = parent::form($form, $form_state);

    $editorial_block_entity_type = $this->entity;
    $form['label'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Label'),
      '#maxlength' => 255,
      '#default_value' => $editorial_block_entity_type->label(),
      '#description' => $this->t("Label for the Editorial block type."),
      '#required' => TRUE,
    ];

    $form['id'] = [
      '#type' => 'machine_name',
      '#default_value' => $editorial_block_entity_type->id(),
      '#machine_name' => [
        'exists' => '\Drupal\editorial_block\Entity\EditorialBlockEntityType::load',
      ],
      '#disabled' => !$editorial_block_entity_type->isNew(),
    ];

    /* You will need additional form elements for your custom properties. */

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function save(array $form, FormStateInterface $form_state) {
    $editorial_block_entity_type = $this->entity;
    $status = $editorial_block_entity_type->save();

    switch ($status) {
      case SAVED_NEW:
        drupal_set_message($this->t('Created the %label Editorial block type.', [
          '%label' => $editorial_block_entity_type->label(),
        ]));
        break;

      default:
        drupal_set_message($this->t('Saved the %label Editorial block type.', [
          '%label' => $editorial_block_entity_type->label(),
        ]));
    }
    $form_state->setRedirectUrl($editorial_block_entity_type->toUrl('collection'));
  }

}
