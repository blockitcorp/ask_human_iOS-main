//
//  MBBlinkIdOverlaySettings.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 03/06/2019.
//

#import "MBBaseOverlaySettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Settings class containing parameters for BlinkId UI
 */
MB_CLASS_AVAILABLE_IOS(13.0)
@interface MBBlinkIdOverlaySettings : MBBaseOverlaySettings

/**
 * If YES, MBBlinkIdMultiSideRecognizer will check if sides do match when scanning is finished
 *
 * Default: YES
 */
@property(nonatomic, assign) BOOL requireDocumentSidesDataMatch;

/**
 * Defines whether Document Not Supported dialog will be displayed in UI.
 *
 * Default: YES
*/
@property(nonatomic, assign) BOOL showNotSupportedDialog;

/**
 * Defines whether glare warning will be displayed when user turn on a flashlight
 *
 * Default: YES
*/
@property(nonatomic, assign) BOOL showFlashlightWarning;

/**
 * Option to configure back side scanning timeout.
 *
 * Default: 17.0
*/
@property(nonatomic, assign) NSTimeInterval backSideScanningTimeout;

/**
* Message that is shown while scanning first side of the document.
* Default: Scan the front side of a document
*/
@property(nonatomic, strong) NSString *firstSideInstructionsText;

/**
* Message that is shown while scanning back side of the document.
* Default: Scan the back side of a document
*/
@property(nonatomic, strong) NSString *backSideInstructionsText;

/**
* Message that is shown after fornt side of the USDL document is scanned.
* Default: Scan the barcode
*/
@property(nonatomic, strong) NSString *scanBarcodeText;

/**
* Instructions to flip document, shown when scanning of the first side is done, before scanning the second
* side of the document.
* Default: Flip the card
*/
@property(nonatomic, strong) NSString *flipInstructions;

/**
* Instructions to scan the passport, shown when scanning of the first side is done, before scanning the second
* side of the document.
* Default: Move to the page on top
*/
@property(nonatomic, strong) NSString *turnTopPageInstructions;

/**
* Instructions to scan the passport, shown when scanning of the first side is done, before scanning the second
* side of the document.
* Default: Move to the page on left
*/
@property(nonatomic, strong) NSString *turnLeftPageInstructions;

/**
* Instructions to scan the passport, shown when scanning of the first side is done, before scanning the second
* side of the document.
* Default: Move to the page on right
*/
@property(nonatomic, strong) NSString *turnRightPageInstructions;

/**
* Instructions to scan the passport, shown when scanning of the first side is done, before scanning the second
* side of the document.
* Default: Move to the page on top
*/
@property(nonatomic, strong) NSString *scanTopPageInstructions;

/**
* Instructions to scan the passport, shown when scanning of the first side is done, before scanning the second
* side of the document.
* Default: Move to the page on left
*/
@property(nonatomic, strong) NSString *scanLeftPageInstructions;

/**
* Instructions to scan the passport, shown when scanning of the first side is done, before scanning the second
* side of the document.
* Default: Move to the page on right
*/
@property(nonatomic, strong) NSString *scanRightPageInstructions;

/**
* Instructions for the user to move the document closer.
* Default: Move closer
*/
@property(nonatomic, strong) NSString *errorMoveCloser;

/**
* Instructions for the user to move the document farther.
* Default: Move farther
*/
@property(nonatomic, strong) NSString *errorMoveFarther;

/**
* Instructions for the user to move the document from the edge.
* Default: Move the document from the edge
*/
@property(nonatomic, strong) NSString *errorDocumentTooCloseToEdge;

/**
* Title of the dialog, which is shown when scanned document sides are not from the same document.
* Default: Sides don't match
*/
@property(nonatomic, strong) NSString *sidesNotMatchingTitle;

/**
* Message inside dialog, which is shown when scanned document sides are not from the same document.
* Default: Please start the scanning process over.
*/
@property(nonatomic, strong) NSString *sidesNotMatchingMessage;

/**
* Title of the dialog, which is shown when scanned document has data mismatch.
* Default: Something went wrong
*/
@property(nonatomic, strong) NSString *dataMismatchTitle;

/**
* Message inside dialog, which is shown when scanned document has data mismatch.
* Default: It appears the information on the document is inconsistent. Please try scanning again.
*/
@property(nonatomic, strong) NSString *dataMismatchMessage;

/**
* Title of the dialog, which is shown when scanned document sides are not from the same document.
* Default: Document not recognized
*/
@property(nonatomic, strong) NSString *unsupportedDocumentTitle;

/**
* Message inside dialog, which is shown when unsupported document is scanned.
* Default: Scan the front side of a supported document.
*/
@property(nonatomic, strong) NSString *unsupportedDocumentMessage;

/**
* Title of the dialog, which is shown on timeout when scanning is stuck on the back document side.
* Default: Scan unsuccessful
*/
@property(nonatomic, strong) NSString *recognitionTimeoutTitle;

/**
* Message inside dialog, which is shown on timeout when scanning is stuck on the back document side.
* Default: Unable to read the document. Please try again.
*/
@property(nonatomic, strong) NSString *recognitionTimeoutMessage;

/**
* Text of the "retry" button inside dialog, which is shown on timeout when scanning is stuck on the back
* document side.
* Default: Retry
*/
@property(nonatomic, strong) NSString *retryButtonText;

/**
* Instructions for the user that is covering more than two mandatory fields for a scan.
* If defineSpecificMissingMandatoryFields is YES, this message will be shown if user is covering any mandatory field.
* Default: Keep the document fully visible
*/
@property(nonatomic, strong) NSString *errorMandatoryFieldMissing;

/**
* If YES and number of missing mandatory fields is <= 2, names of missing mandatory fields will be present in the message.
*
* Default: NO
*/
@property(nonatomic, assign) BOOL defineSpecificMissingMandatoryFields;

/**
* Option to configure when the onboarding help tooltip will appear.
* Default: 8.0
*/
@property(nonatomic, assign) NSTimeInterval onboardingButtonTooltipDelay;

/**
* Defines whether button for presenting onboarding screens will be present on screen.
* Default: YES
*/
@property(nonatomic, assign) BOOL showOnboardingInfo;

/**
* Defines whether tutorial alert will be presented on appear.
* Default: NO
*/
@property(nonatomic, assign) BOOL showIntroductionDialog;

/**
* Instructions for the user to avoid glare.
* Default: Tilt or move document to remove reflection
*/
@property(nonatomic, strong) NSString *glareDetectedMessage;

/**
* Instructions for the user to avoid blur.
* Default: Keep document and phone still
*/
@property(nonatomic, strong) NSString *blurDetectedMessage;

/**
* Instructions for the user when face image is missing.
* Default: Keep face photo fully visible
*/
@property(nonatomic, strong) NSString *faceImageMissingMessage;

/**
* Instructions for the user when other side is awaiting scanning.
* Default: Flip the document
*/
@property(nonatomic, strong) NSString *awaitingOtherSideMessage;

/**
* Instructions for the user when wrong side is being scanned.
* Default: Flip the document
*/
@property(nonatomic, strong) NSString *scanningWrongSideMessage;

/**
* Instructions for the user when wrong side of passport is being scanned.
* Default: Move to the top
*/
@property(nonatomic, strong) NSString *scanningWrongSidePassportTopMessage;

/**
* Instructions for the user when wrong side of passport is being scanned.
* Default: Move to the right
*/
@property(nonatomic, strong) NSString *scanningWrongSidePassportRightMessage;

/**
* Instructions for the user when wrong side of passport is being scanned.
* Default: Move to the left
*/
@property(nonatomic, strong) NSString *scanningWrongSidePassportLeftMessage;

/**
 * Designated initializer. Initializes the object with default settings.
 *
 *  @return object initialized with default values.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
