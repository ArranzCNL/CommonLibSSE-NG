#pragma once

namespace RE
{
	struct hkpConstraintAtom
	{
	public:
		enum AtomType
		{
			kInvalid = 0,

			kBridge,

			kSetLocalTransforms,
			kSetLocalTranslations,
			kSetLocalRotations,

			kBallSocket,
			kStiffSpring,

			kLin,
			kLinSoft,
			kLinLimit,
			kLinFriction,
			kLinMotor,

			k2DAng,

			kAng,
			kAngLimit,
			kTwistLimit,
			kConeLimit,
			kAngFriction,
			kAngMotor,

			kRagdollMotor,

			kPulley,
			kRackAndPinion,
			kCogWheel,

			kSetupStabilization,

			kOverwritePivot,

			kContact,

			// modifiers
			kModifier_SoftContact,
			kModifier_MassChanger,
			kModifier_ViscousSurface,
			kModifier_MovingSurface,
			kModifier_IgnoreConstraint,
			kModifier_CenterOfMassChanger,

			kMAX
		};

		enum SolvingMethod : std::uint8_t
		{
			kStabilized = 0,
			kOld = 1,
		};

		// members
		stl::enumeration<AtomType, std::uint16_t> type;
	};
	static_assert(sizeof(hkpConstraintAtom) == 0x2);

	struct hkpSetupStabilizationAtom : public hkpConstraintAtom
	{
		bool          enabled;   // 02
		float         maxAngle;  // 04
		std::uint64_t pad08;     // 08
	};
	static_assert(sizeof(hkpSetupStabilizationAtom) == 0x10);

	struct hkpBallSocketConstraintAtom : public hkpConstraintAtom
	{
		SolvingMethod solvingMethod;                // 02
		std::uint8_t  bodiesToNotify;               // 03
		hkUFloat8     velocityStabilizationFactor;  // 04
		float         maxImpulse;                   // 08
		float         inertiaStabilizationFactor;   // 0C
	};
	static_assert(sizeof(hkpBallSocketConstraintAtom) == 0x10);

	struct hkpSetLocalTransformsConstraintAtom : public hkpConstraintAtom
	{
		std::uint32_t pad02;       // 02
		hkTransform   transformA;  // 10
		hkTransform   transformB;  // 50
	};
	static_assert(sizeof(hkpSetLocalTransformsConstraintAtom) == 0x90);

	struct hkp2dAngConstraintAtom : public hkpConstraintAtom
	{
		std::uint8_t freeRotationAxis;  // 02
	};
	static_assert(sizeof(hkp2dAngConstraintAtom) == 0x4);

	struct hkpAngLimitConstraintAtom : public hkpConstraintAtom
	{
		bool         enabled;                 // 02
		std::uint8_t limitAxis;               // 03
		float        minAngle;                // 04
		float        maxAngle;                // 08
		float        angularLimitsTauFactor;  // 0C
	};
	static_assert(sizeof(hkpAngLimitConstraintAtom) == 0x10);

	struct hkpTwistLimitConstraintAtom : public hkpConstraintAtom
	{
		bool         enabled;                 // 02
		std::uint8_t twistAxis;               // 03
		std::uint8_t refAxis;                 // 04
		float        minAngle;                // 08
		float        maxAngle;                // 0C
		float        angularLimitsTauFactor;  // 10
	};
	static_assert(sizeof(hkpTwistLimitConstraintAtom) == 0x14);

	struct hkpConeLimitConstraintAtom : public hkpConstraintAtom
	{
		enum MeasurementMode : std::uint8_t
		{
			kZeroWhenVectorsAligned = 0,
			kZeroWhenVectorsPerpendicular = 1
		};

		bool            enabled;                 // 02
		std::uint8_t    twistAxisInA;            // 03
		std::uint8_t    refAxisInB;              // 04
		MeasurementMode angleMeasurementMode;    // 05
		std::uint8_t    memOffsetToAngleOffset;  // 06
		float           minAngle;                // 08
		float           maxAngle;                // 0C
		float           angularLimitsTauFactor;  // 10
	};
	static_assert(sizeof(hkpConeLimitConstraintAtom) == 0x14);

	struct hkpAngFrictionConstraintAtom : public hkpConstraintAtom
	{
		bool         enabled;            // 02
		std::uint8_t firstFrictionAxis;  // 03
		std::uint8_t numFrictionAxes;    // 04
		float        maxFrictionTorque;  // 08
	};
	static_assert(sizeof(hkpAngFrictionConstraintAtom) == 0xC);

	struct hkpAngMotorConstraintAtom : public hkpConstraintAtom
	{
		bool           enabled;                                  // 02
		std::uint8_t   motorAxis;                                // 03
		std::int16_t   initializedOffset;                        // 04
		std::int16_t   previousTargetAngleOffset;                // 06
		std::int16_t   correspondingAngLimitSolverResultOffset;  // 08
		float          targetAngle;                              // 0C
		std::uintptr_t motor;                                    // 10
	};
	static_assert(sizeof(hkpAngMotorConstraintAtom) == 0x18);

	struct hkpRagdollMotorConstraintAtom : public hkpConstraintAtom
	{
		bool           enabled;                     // 02
		std::int16_t   initializedOffset;           // 04
		std::int16_t   previousTargetAnglesOffset;  // 06
		hkMatrix3      target_bRca;                 // 10
		std::uintptr_t motors[3];                   // 40
	};
	static_assert(sizeof(hkpRagdollMotorConstraintAtom) == 0x60);
}
