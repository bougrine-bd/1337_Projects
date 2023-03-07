<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://codex.wordpress.org/Editing_wp-config.php
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'wpress' );

/** MySQL database password */
define( 'DB_PASSWORD', 'wpress' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         'KM|UZGhQk{`ly.$4w%oo?qrm4wG:-qL^DFlmuLbVit[p+GV*/QuSCym;v-!$FRBO' );
define( 'SECURE_AUTH_KEY',  ')5_?n~NlZ[t&v,V}d2($W&@M*i.R>^<lQABK9dq>g/m7X9?:xQ7Q[G2-GD//Z#um' );
define( 'LOGGED_IN_KEY',    '!A7x!68%2(AlI0C=uidCk}Q4V&G$:O_8pyjonbq<@SBRA%is``j%A5/+|b)W)K`D' );
define( 'NONCE_KEY',        '_(8K3M<MwqvgRzKdy35CWaS9p8B<inj_$6Qi}+YOFRszKCG|Kf!SA DyP8t-5IqM' );
define( 'AUTH_SALT',        'zOlCv*F!Y}WhZ9SSE- WDg<l!:}_y2ugVA_2/RV!xxOom?GbWqa|dKAkW:(2z) F' );
define( 'SECURE_AUTH_SALT', '8U65< pw@Rf=2@<zqNj~$K%FfRdqWWx_1?xRl`BC8%o>6`@^*!:p*|s4&NPOMy0r' );
define( 'LOGGED_IN_SALT',   'MHj`n9JaPu &=geGT5maByrn!SeH`q%/iyJ]69>n5{2vgf}6VvgJ2aR.r]T&tR]F' );
define( 'NONCE_SALT',       '0qBSh%sAL*@1^;l}m8VjH>,1zS$kv1wup]RLBa@g(Y(*NrD=J]$J2xU)L-)@}4#Q' );

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );