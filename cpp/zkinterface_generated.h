// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_ZKINTERFACE_ZKINTERFACE_H_
#define FLATBUFFERS_GENERATED_ZKINTERFACE_ZKINTERFACE_H_

#include "flatbuffers/flatbuffers.h"

namespace zkinterface {

struct Circuit;

struct KeyValue;

struct R1CSConstraints;

struct BilinearConstraint;

struct Witness;

struct Variables;

struct Root;

/// The messages that the caller and gadget can exchange.
enum Message {
  Message_NONE = 0,
  Message_Circuit = 1,
  Message_R1CSConstraints = 2,
  Message_Witness = 3,
  Message_MIN = Message_NONE,
  Message_MAX = Message_Witness
};

inline const Message (&EnumValuesMessage())[4] {
  static const Message values[] = {
    Message_NONE,
    Message_Circuit,
    Message_R1CSConstraints,
    Message_Witness
  };
  return values;
}

inline const char * const *EnumNamesMessage() {
  static const char * const names[] = {
    "NONE",
    "Circuit",
    "R1CSConstraints",
    "Witness",
    nullptr
  };
  return names;
}

inline const char *EnumNameMessage(Message e) {
  if (e < Message_NONE || e > Message_Witness) return "";
  const size_t index = static_cast<int>(e);
  return EnumNamesMessage()[index];
}

template<typename T> struct MessageTraits {
  static const Message enum_value = Message_NONE;
};

template<> struct MessageTraits<Circuit> {
  static const Message enum_value = Message_Circuit;
};

template<> struct MessageTraits<R1CSConstraints> {
  static const Message enum_value = Message_R1CSConstraints;
};

template<> struct MessageTraits<Witness> {
  static const Message enum_value = Message_Witness;
};

bool VerifyMessage(flatbuffers::Verifier &verifier, const void *obj, Message type);
bool VerifyMessageVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types);

/// A description of the connection of a circuit or sub-circuit.
/// This can be a complete circuit ready for proving,
/// or a part of a circuit being built.
struct Circuit FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_CONNECTIONS = 4,
    VT_FREE_VARIABLE_ID = 6,
    VT_R1CS_GENERATION = 8,
    VT_WITNESS_GENERATION = 10,
    VT_FIELD_ORDER = 12,
    VT_CONFIGURATION = 14
  };
  /// Variables to use as connection to the sub-circuit.
  /// - Variables to use as input connections to the gadget.
  /// - Or variables to use as output connections from the gadget.
  /// - Variables are allocated by the sender of this message.
  /// - The same structure must be provided for R1CS and witness generation.
  const Variables *connections() const {
    return GetPointer<const Variables *>(VT_CONNECTIONS);
  }
  /// First variable ID free after this connection.
  /// A variable ID greater than all IDs allocated by the sender of this message.
  /// The recipient of this message can allocate new IDs greater than `free_variable_id`.
  uint64_t free_variable_id() const {
    return GetField<uint64_t>(VT_FREE_VARIABLE_ID, 0);
  }
  /// Whether constraints should be generated.
  bool r1cs_generation() const {
    return GetField<uint8_t>(VT_R1CS_GENERATION, 0) != 0;
  }
  /// Whether an witness should be generated.
  /// Provide witness values to the gadget.
  bool witness_generation() const {
    return GetField<uint8_t>(VT_WITNESS_GENERATION, 0) != 0;
  }
  /// The order of the field used by the current system.
  /// A BigInt.
  const flatbuffers::Vector<uint8_t> *field_order() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_FIELD_ORDER);
  }
  /// Optional: Any static parameter that may influence the instance
  /// construction. Parameters can be standard, conventional, or custom.
  /// Example: function_name, if a gadget supports multiple function variants.
  /// Example: the depth of a Merkle tree.
  /// Counter-example: a Merkle path is not configuration (rather witness).
  const flatbuffers::Vector<flatbuffers::Offset<KeyValue>> *configuration() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<KeyValue>> *>(VT_CONFIGURATION);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_CONNECTIONS) &&
           verifier.VerifyTable(connections()) &&
           VerifyField<uint64_t>(verifier, VT_FREE_VARIABLE_ID) &&
           VerifyField<uint8_t>(verifier, VT_R1CS_GENERATION) &&
           VerifyField<uint8_t>(verifier, VT_WITNESS_GENERATION) &&
           VerifyOffset(verifier, VT_FIELD_ORDER) &&
           verifier.VerifyVector(field_order()) &&
           VerifyOffset(verifier, VT_CONFIGURATION) &&
           verifier.VerifyVector(configuration()) &&
           verifier.VerifyVectorOfTables(configuration()) &&
           verifier.EndTable();
  }
};

struct CircuitBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_connections(flatbuffers::Offset<Variables> connections) {
    fbb_.AddOffset(Circuit::VT_CONNECTIONS, connections);
  }
  void add_free_variable_id(uint64_t free_variable_id) {
    fbb_.AddElement<uint64_t>(Circuit::VT_FREE_VARIABLE_ID, free_variable_id, 0);
  }
  void add_r1cs_generation(bool r1cs_generation) {
    fbb_.AddElement<uint8_t>(Circuit::VT_R1CS_GENERATION, static_cast<uint8_t>(r1cs_generation), 0);
  }
  void add_witness_generation(bool witness_generation) {
    fbb_.AddElement<uint8_t>(Circuit::VT_WITNESS_GENERATION, static_cast<uint8_t>(witness_generation), 0);
  }
  void add_field_order(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> field_order) {
    fbb_.AddOffset(Circuit::VT_FIELD_ORDER, field_order);
  }
  void add_configuration(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<KeyValue>>> configuration) {
    fbb_.AddOffset(Circuit::VT_CONFIGURATION, configuration);
  }
  explicit CircuitBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  CircuitBuilder &operator=(const CircuitBuilder &);
  flatbuffers::Offset<Circuit> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Circuit>(end);
    return o;
  }
};

inline flatbuffers::Offset<Circuit> CreateCircuit(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<Variables> connections = 0,
    uint64_t free_variable_id = 0,
    bool r1cs_generation = false,
    bool witness_generation = false,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> field_order = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<KeyValue>>> configuration = 0) {
  CircuitBuilder builder_(_fbb);
  builder_.add_free_variable_id(free_variable_id);
  builder_.add_configuration(configuration);
  builder_.add_field_order(field_order);
  builder_.add_connections(connections);
  builder_.add_witness_generation(witness_generation);
  builder_.add_r1cs_generation(r1cs_generation);
  return builder_.Finish();
}

inline flatbuffers::Offset<Circuit> CreateCircuitDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<Variables> connections = 0,
    uint64_t free_variable_id = 0,
    bool r1cs_generation = false,
    bool witness_generation = false,
    const std::vector<uint8_t> *field_order = nullptr,
    const std::vector<flatbuffers::Offset<KeyValue>> *configuration = nullptr) {
  auto field_order__ = field_order ? _fbb.CreateVector<uint8_t>(*field_order) : 0;
  auto configuration__ = configuration ? _fbb.CreateVector<flatbuffers::Offset<KeyValue>>(*configuration) : 0;
  return zkinterface::CreateCircuit(
      _fbb,
      connections,
      free_variable_id,
      r1cs_generation,
      witness_generation,
      field_order__,
      configuration__);
}

/// Generic key-value for custom attributes.
struct KeyValue FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_KEY = 4,
    VT_VALUE = 6
  };
  const flatbuffers::String *key() const {
    return GetPointer<const flatbuffers::String *>(VT_KEY);
  }
  const flatbuffers::Vector<uint8_t> *value() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_VALUE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_KEY) &&
           verifier.VerifyString(key()) &&
           VerifyOffset(verifier, VT_VALUE) &&
           verifier.VerifyVector(value()) &&
           verifier.EndTable();
  }
};

struct KeyValueBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_key(flatbuffers::Offset<flatbuffers::String> key) {
    fbb_.AddOffset(KeyValue::VT_KEY, key);
  }
  void add_value(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> value) {
    fbb_.AddOffset(KeyValue::VT_VALUE, value);
  }
  explicit KeyValueBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  KeyValueBuilder &operator=(const KeyValueBuilder &);
  flatbuffers::Offset<KeyValue> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<KeyValue>(end);
    return o;
  }
};

inline flatbuffers::Offset<KeyValue> CreateKeyValue(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> key = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> value = 0) {
  KeyValueBuilder builder_(_fbb);
  builder_.add_value(value);
  builder_.add_key(key);
  return builder_.Finish();
}

inline flatbuffers::Offset<KeyValue> CreateKeyValueDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *key = nullptr,
    const std::vector<uint8_t> *value = nullptr) {
  auto key__ = key ? _fbb.CreateString(key) : 0;
  auto value__ = value ? _fbb.CreateVector<uint8_t>(*value) : 0;
  return zkinterface::CreateKeyValue(
      _fbb,
      key__,
      value__);
}

/// Report constraints to be added to the constraints system.
/// To send to the stream of constraints.
struct R1CSConstraints FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_CONSTRAINTS = 4
  };
  const flatbuffers::Vector<flatbuffers::Offset<BilinearConstraint>> *constraints() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<BilinearConstraint>> *>(VT_CONSTRAINTS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_CONSTRAINTS) &&
           verifier.VerifyVector(constraints()) &&
           verifier.VerifyVectorOfTables(constraints()) &&
           verifier.EndTable();
  }
};

struct R1CSConstraintsBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_constraints(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<BilinearConstraint>>> constraints) {
    fbb_.AddOffset(R1CSConstraints::VT_CONSTRAINTS, constraints);
  }
  explicit R1CSConstraintsBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  R1CSConstraintsBuilder &operator=(const R1CSConstraintsBuilder &);
  flatbuffers::Offset<R1CSConstraints> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<R1CSConstraints>(end);
    return o;
  }
};

inline flatbuffers::Offset<R1CSConstraints> CreateR1CSConstraints(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<BilinearConstraint>>> constraints = 0) {
  R1CSConstraintsBuilder builder_(_fbb);
  builder_.add_constraints(constraints);
  return builder_.Finish();
}

inline flatbuffers::Offset<R1CSConstraints> CreateR1CSConstraintsDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<BilinearConstraint>> *constraints = nullptr) {
  auto constraints__ = constraints ? _fbb.CreateVector<flatbuffers::Offset<BilinearConstraint>>(*constraints) : 0;
  return zkinterface::CreateR1CSConstraints(
      _fbb,
      constraints__);
}

/// An R1CS constraint between variables.
struct BilinearConstraint FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_LINEAR_COMBINATION_A = 4,
    VT_LINEAR_COMBINATION_B = 6,
    VT_LINEAR_COMBINATION_C = 8
  };
  const Variables *linear_combination_a() const {
    return GetPointer<const Variables *>(VT_LINEAR_COMBINATION_A);
  }
  const Variables *linear_combination_b() const {
    return GetPointer<const Variables *>(VT_LINEAR_COMBINATION_B);
  }
  const Variables *linear_combination_c() const {
    return GetPointer<const Variables *>(VT_LINEAR_COMBINATION_C);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_LINEAR_COMBINATION_A) &&
           verifier.VerifyTable(linear_combination_a()) &&
           VerifyOffset(verifier, VT_LINEAR_COMBINATION_B) &&
           verifier.VerifyTable(linear_combination_b()) &&
           VerifyOffset(verifier, VT_LINEAR_COMBINATION_C) &&
           verifier.VerifyTable(linear_combination_c()) &&
           verifier.EndTable();
  }
};

struct BilinearConstraintBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_linear_combination_a(flatbuffers::Offset<Variables> linear_combination_a) {
    fbb_.AddOffset(BilinearConstraint::VT_LINEAR_COMBINATION_A, linear_combination_a);
  }
  void add_linear_combination_b(flatbuffers::Offset<Variables> linear_combination_b) {
    fbb_.AddOffset(BilinearConstraint::VT_LINEAR_COMBINATION_B, linear_combination_b);
  }
  void add_linear_combination_c(flatbuffers::Offset<Variables> linear_combination_c) {
    fbb_.AddOffset(BilinearConstraint::VT_LINEAR_COMBINATION_C, linear_combination_c);
  }
  explicit BilinearConstraintBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  BilinearConstraintBuilder &operator=(const BilinearConstraintBuilder &);
  flatbuffers::Offset<BilinearConstraint> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<BilinearConstraint>(end);
    return o;
  }
};

inline flatbuffers::Offset<BilinearConstraint> CreateBilinearConstraint(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<Variables> linear_combination_a = 0,
    flatbuffers::Offset<Variables> linear_combination_b = 0,
    flatbuffers::Offset<Variables> linear_combination_c = 0) {
  BilinearConstraintBuilder builder_(_fbb);
  builder_.add_linear_combination_c(linear_combination_c);
  builder_.add_linear_combination_b(linear_combination_b);
  builder_.add_linear_combination_a(linear_combination_a);
  return builder_.Finish();
}

/// Report local assignments computed by the gadget.
/// To send to the stream of assigned variables.
/// Does not include input and output variables.
struct Witness FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_VALUES = 4
  };
  const Variables *values() const {
    return GetPointer<const Variables *>(VT_VALUES);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_VALUES) &&
           verifier.VerifyTable(values()) &&
           verifier.EndTable();
  }
};

struct WitnessBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_values(flatbuffers::Offset<Variables> values) {
    fbb_.AddOffset(Witness::VT_VALUES, values);
  }
  explicit WitnessBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  WitnessBuilder &operator=(const WitnessBuilder &);
  flatbuffers::Offset<Witness> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Witness>(end);
    return o;
  }
};

inline flatbuffers::Offset<Witness> CreateWitness(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<Variables> values = 0) {
  WitnessBuilder builder_(_fbb);
  builder_.add_values(values);
  return builder_.Finish();
}

/// Concrete variable values.
/// Used for linear combinations and assignments.
struct Variables FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_VARIABLE_IDS = 4,
    VT_VALUES = 6,
    VT_INFO = 8
  };
  /// The IDs of the variables being assigned to.
  const flatbuffers::Vector<uint64_t> *variable_ids() const {
    return GetPointer<const flatbuffers::Vector<uint64_t> *>(VT_VARIABLE_IDS);
  }
  /// Optional: Field elements assigned to variables.
  /// Contiguous BigInts in the same order as variable_ids.
  ///
  /// The field in use is defined in `instance.field_order`.
  ///
  /// The size of an element representation is determined by:
  ///     element size = elements.length / variable_ids.length
  ///
  /// The element representation may be truncated and therefore shorter
  /// than the canonical representation. Truncated bytes are treated as zeros.
  const flatbuffers::Vector<uint8_t> *values() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_VALUES);
  }
  /// Optional: Any complementary info that may be useful to the recipient.
  /// Example: a Merkle authentication path.
  const flatbuffers::Vector<flatbuffers::Offset<KeyValue>> *info() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<KeyValue>> *>(VT_INFO);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_VARIABLE_IDS) &&
           verifier.VerifyVector(variable_ids()) &&
           VerifyOffset(verifier, VT_VALUES) &&
           verifier.VerifyVector(values()) &&
           VerifyOffset(verifier, VT_INFO) &&
           verifier.VerifyVector(info()) &&
           verifier.VerifyVectorOfTables(info()) &&
           verifier.EndTable();
  }
};

struct VariablesBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_variable_ids(flatbuffers::Offset<flatbuffers::Vector<uint64_t>> variable_ids) {
    fbb_.AddOffset(Variables::VT_VARIABLE_IDS, variable_ids);
  }
  void add_values(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> values) {
    fbb_.AddOffset(Variables::VT_VALUES, values);
  }
  void add_info(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<KeyValue>>> info) {
    fbb_.AddOffset(Variables::VT_INFO, info);
  }
  explicit VariablesBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  VariablesBuilder &operator=(const VariablesBuilder &);
  flatbuffers::Offset<Variables> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Variables>(end);
    return o;
  }
};

inline flatbuffers::Offset<Variables> CreateVariables(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<uint64_t>> variable_ids = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> values = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<KeyValue>>> info = 0) {
  VariablesBuilder builder_(_fbb);
  builder_.add_info(info);
  builder_.add_values(values);
  builder_.add_variable_ids(variable_ids);
  return builder_.Finish();
}

inline flatbuffers::Offset<Variables> CreateVariablesDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<uint64_t> *variable_ids = nullptr,
    const std::vector<uint8_t> *values = nullptr,
    const std::vector<flatbuffers::Offset<KeyValue>> *info = nullptr) {
  auto variable_ids__ = variable_ids ? _fbb.CreateVector<uint64_t>(*variable_ids) : 0;
  auto values__ = values ? _fbb.CreateVector<uint8_t>(*values) : 0;
  auto info__ = info ? _fbb.CreateVector<flatbuffers::Offset<KeyValue>>(*info) : 0;
  return zkinterface::CreateVariables(
      _fbb,
      variable_ids__,
      values__,
      info__);
}

struct Root FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_MESSAGE_TYPE = 4,
    VT_MESSAGE = 6
  };
  Message message_type() const {
    return static_cast<Message>(GetField<uint8_t>(VT_MESSAGE_TYPE, 0));
  }
  const void *message() const {
    return GetPointer<const void *>(VT_MESSAGE);
  }
  template<typename T> const T *message_as() const;
  const Circuit *message_as_Circuit() const {
    return message_type() == Message_Circuit ? static_cast<const Circuit *>(message()) : nullptr;
  }
  const R1CSConstraints *message_as_R1CSConstraints() const {
    return message_type() == Message_R1CSConstraints ? static_cast<const R1CSConstraints *>(message()) : nullptr;
  }
  const Witness *message_as_Witness() const {
    return message_type() == Message_Witness ? static_cast<const Witness *>(message()) : nullptr;
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_MESSAGE_TYPE) &&
           VerifyOffset(verifier, VT_MESSAGE) &&
           VerifyMessage(verifier, message(), message_type()) &&
           verifier.EndTable();
  }
};

template<> inline const Circuit *Root::message_as<Circuit>() const {
  return message_as_Circuit();
}

template<> inline const R1CSConstraints *Root::message_as<R1CSConstraints>() const {
  return message_as_R1CSConstraints();
}

template<> inline const Witness *Root::message_as<Witness>() const {
  return message_as_Witness();
}

struct RootBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_message_type(Message message_type) {
    fbb_.AddElement<uint8_t>(Root::VT_MESSAGE_TYPE, static_cast<uint8_t>(message_type), 0);
  }
  void add_message(flatbuffers::Offset<void> message) {
    fbb_.AddOffset(Root::VT_MESSAGE, message);
  }
  explicit RootBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  RootBuilder &operator=(const RootBuilder &);
  flatbuffers::Offset<Root> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Root>(end);
    return o;
  }
};

inline flatbuffers::Offset<Root> CreateRoot(
    flatbuffers::FlatBufferBuilder &_fbb,
    Message message_type = Message_NONE,
    flatbuffers::Offset<void> message = 0) {
  RootBuilder builder_(_fbb);
  builder_.add_message(message);
  builder_.add_message_type(message_type);
  return builder_.Finish();
}

inline bool VerifyMessage(flatbuffers::Verifier &verifier, const void *obj, Message type) {
  switch (type) {
    case Message_NONE: {
      return true;
    }
    case Message_Circuit: {
      auto ptr = reinterpret_cast<const Circuit *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Message_R1CSConstraints: {
      auto ptr = reinterpret_cast<const R1CSConstraints *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Message_Witness: {
      auto ptr = reinterpret_cast<const Witness *>(obj);
      return verifier.VerifyTable(ptr);
    }
    default: return false;
  }
}

inline bool VerifyMessageVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types) {
  if (!values || !types) return !values && !types;
  if (values->size() != types->size()) return false;
  for (flatbuffers::uoffset_t i = 0; i < values->size(); ++i) {
    if (!VerifyMessage(
        verifier,  values->Get(i), types->GetEnum<Message>(i))) {
      return false;
    }
  }
  return true;
}

inline const zkinterface::Root *GetRoot(const void *buf) {
  return flatbuffers::GetRoot<zkinterface::Root>(buf);
}

inline const zkinterface::Root *GetSizePrefixedRoot(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<zkinterface::Root>(buf);
}

inline const char *RootIdentifier() {
  return "zkif";
}

inline bool RootBufferHasIdentifier(const void *buf) {
  return flatbuffers::BufferHasIdentifier(
      buf, RootIdentifier());
}

inline bool VerifyRootBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<zkinterface::Root>(RootIdentifier());
}

inline bool VerifySizePrefixedRootBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<zkinterface::Root>(RootIdentifier());
}

inline const char *RootExtension() {
  return "zkif";
}

inline void FinishRootBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<zkinterface::Root> root) {
  fbb.Finish(root, RootIdentifier());
}

inline void FinishSizePrefixedRootBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<zkinterface::Root> root) {
  fbb.FinishSizePrefixed(root, RootIdentifier());
}

}  // namespace zkinterface

#endif  // FLATBUFFERS_GENERATED_ZKINTERFACE_ZKINTERFACE_H_
