//
//  CustomSlider.swift
//  ask-human
//
//  Created by IDEIO SOFT on 10/01/25.
//

import UIKit
import MaterialComponents

class CustomSlider: UIView {

    private let slider = MDCSlider()
    let thumbLabel = UILabel()
    var index = 0
    var type = 0
    // Public properties for customization
    var minimumValue: Float = 0 {
        didSet {
            slider.minimumValue = CGFloat(minimumValue)
            updateThumbLabelPosition()
        }
    }

    var maximumValue: Float = 100 {
        didSet {
            slider.maximumValue = CGFloat(maximumValue)
            updateThumbLabelPosition()
        }
    }

    var currentValue: Float = 50 {
        didSet {
            slider.value = CGFloat(currentValue)
         
            updateThumbLabelPosition()
        }
    }
    
    // Thumb border color property
    var thumbBorderColor: UIColor = .black {
        didSet {
            updateThumbImageBorderColor()
        }
    }

    // Initializer
    override init(frame: CGRect) {
        super.init(frame: frame)
        setupSlider()
    }

    required init?(coder: NSCoder) {
        super.init(coder: coder)
        setupSlider()
    }

    private func setupSlider() {
        // Set initial values for the slider
        slider.minimumValue = CGFloat(minimumValue)
        slider.maximumValue = CGFloat(maximumValue)
        slider.value = CGFloat(currentValue)
        
        // Configure the slider appearance
        slider.addTarget(self, action: #selector(sliderValueChanged(_:)), for: .valueChanged)
        slider.trackHeight = 8
        slider.thumbRadius = 9
        slider.layer.cornerRadius = 2.0
        slider.layer.masksToBounds = true
        slider.trackBackgroundColor = UIColor(hex: "#D9D9D9")
        
        slider.trackEndsAreRounded = true
        addSubview(slider)

        // Set the custom thumb image with a border
        setThumbImageWithBorder()

        // Configure the thumb label appearance
        thumbLabel.textColor = .black
        thumbLabel.textAlignment = .center
        thumbLabel.font = UIFont.systemFont(ofSize: 11)
        thumbLabel.layer.cornerRadius = 5
        thumbLabel.layer.masksToBounds = true
        thumbLabel.backgroundColor = .white
        
        thumbLabel.frame = CGRect(x: 0, y: 0, width: 50, height: 25)
      
        if type == 1{
           thumbLabel.text = "\(Int(slider.value)) Star"
            
        }else if type == 2{
            if index == 1{
                thumbLabel.text = "\(Int(slider.value)) Star"
            }else{
                thumbLabel.text = "\(Int(slider.value)) Star"
            }
        }else{
            if index == 0{
                thumbLabel.text = "\(Int(slider.value)) Star"
            }else{
                thumbLabel.text = "\(Int(slider.value)) Star"
            }
        }
        addSubview(thumbLabel)

        // Initial positioning of the thumb label
        updateThumbLabelPosition()
    }

    override func layoutSubviews() {
        super.layoutSubviews()
        slider.frame = CGRect(x: 0, y: bounds.height / 2 - 20, width: bounds.width, height: 40)
        updateThumbLabelPosition()
    }

    @objc private func sliderValueChanged(_ sender: MDCSlider) {
        print("valuerr",sender.value)
        if type == 1{
            thumbLabel.text = "\(Int(slider.value)) Star"
            ratingFilter = "\(Int(slider.value)) Star"

        }else if type == 2{
            if index == 1{
                endingSoon = Int(sender.value)
                isSelectEndingSoon = true
                thumbLabel.text = "\(Int(slider.value)) Star"
            }else if index == 2{
                ratingFilter = String(Int(sender.value))
                thumbLabel.text = "\(Int(slider.value)) Star"
            }
        }else{
            if index == 0{
                ratingFilter = String(Int(sender.value))
                thumbLabel.text = "\(Int(slider.value)) Star"
            }else if index == 2{
                rating = Int(sender.value)
                isSelectRating = true
                thumbLabel.text = "\(Int(slider.value)) Star"
            }
        }
        updateThumbLabelPosition()
    }

//    private func updateThumbLabelPosition() {
//        // Calculate the thumb's position
//        let trackWidth = slider.bounds.width - 30  // Adjust for thumb width
//
//        let thumbX = CGFloat(slider.value - slider.minimumValue) / CGFloat(slider.maximumValue - slider.minimumValue) * trackWidth + 15
//        let thumbY = slider.center.y - 30
//
//        // Update the label's position
//        thumbLabel.center = CGPoint(x: thumbX, y: thumbY)
//    }
    private func updateThumbLabelPosition() {
        let trackWidth = slider.bounds.width - 30  // Adjust for thumb width
        // Prevent division by zero
        if slider.maximumValue != slider.minimumValue {
            let thumbX = CGFloat(slider.value - slider.minimumValue) / CGFloat(slider.maximumValue - slider.minimumValue) * trackWidth + 15  // Adjust for thumb size
            let thumbY = slider.center.y - 30

            // Update the label's position
            thumbLabel.center = CGPoint(x: thumbX, y: thumbY)
        } else {
            // Handle the case where max and min values are equal (invalid state)
            print("Warning: Slider minimum and maximum values are equal.")
        }
    }

    private func setThumbImageWithBorder() {
        // Create a custom thumb image with a border
        let thumbSize = CGSize(width: 20, height: 20)
        UIGraphicsBeginImageContextWithOptions(thumbSize, false, 0)

        let context = UIGraphicsGetCurrentContext()

        // Draw the thumb circle with a border
        let thumbPath = UIBezierPath(ovalIn: CGRect(origin: .zero, size: thumbSize))
        context?.setFillColor(UIColor.app.cgColor)  // Fill color
      
        // Create the image
        let thumbImage = UIGraphicsGetImageFromCurrentImageContext()
        UIGraphicsEndImageContext()

        // Set the custom thumb image
        slider.setThumbColor(.app, for: .normal)
    }

    private func updateThumbImageBorderColor() {
        // Update the thumb image border color
        setThumbImageWithBorder()
    }
}
