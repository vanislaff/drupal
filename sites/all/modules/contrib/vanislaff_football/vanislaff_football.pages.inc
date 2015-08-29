<?php

function just_a_word() {
    return 'test';
}

function get_teams() {
    $teams = db_select('node', 'n')
            ->fields('n')
            ->condition('n.type', 'teams_football', '=')
            ->execute()
            ->fetchAll();

    return $teams;
}

function get_teams_list() {
    $output = '';

    $teams = get_teams();
    if ($teams) {
        $output .= '<ul>';
        foreach ($teams as $key => $team) {
            $output .= '<li>';
            $output .= l($team->title, 'node/' . $team->nid, array('attributes' => array('class' => array('class-a', 'class-b'))));
            $output .= '</li>';
        }
        $output .= '</ul>';
    }

    return $output;
}
